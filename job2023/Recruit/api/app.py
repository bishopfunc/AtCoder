from flask import Flask, request, jsonify, Response
import base64
import re
import sqlite3

app = Flask(__name__)

conn = sqlite3.connect('database.db')
cursor = conn.cursor()

create_table_query = '''
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id TEXT,
    password TEXT,
    comment TEXT NULL,
    nickname TEXT NULL
);
'''
cursor.execute(create_table_query)
conn.commit()

cursor.close()
conn.close()

class Validate:
    def __init__(self, user_id, password):
        self.cause_list = []
        self.user_id = user_id
        self.password = password

    def get_flag_cause(self):
        self.validate_user_id()
        self.check_exist_user() 
        self.validate_password()
        if len(self.cause_list) == 0:
            return True, None
        return False, ','.join(self.cause_list)
    
    def validate_password(self):
        if len(self.password) < 8 or len(self.password) > 20:
            self.cause_list.append('password must be 8 to 20 characters long.')
        if not re.match(r'^[a-zA-Z0-9]+$', self.password):
            self.cause_list.append('password must consist of alphanumeric characters.')
        if not self.password:
            self.cause_list.append('password is required.')

    def validate_user_id(self):
        if len(self.user_id) < 6 or len(self.user_id) > 20:
            self.cause_list.append('user_id must be 6 to 20 characters long.')
        if not re.match(r'^[a-zA-Z0-9]+$', self.user_id):
            self.cause_list.append('user_id must consist of alphabet and number characters.')
        if not self.user_id:
            self.cause_list.append('user_id is required.')
        
    def check_exist_user(self):
        if result := get_db_user(self.user_id):
            self.cause_list.append('user_id already exists.')

def get_db_user(user_id):
    query = "SELECT * FROM users WHERE user_id = ?"
    conn = sqlite3.connect('database.db')
    cursor = conn.cursor()
    cursor.execute(query, (user_id,))
    row = cursor.fetchone()
    if row:
        columns = [column[0] for column in cursor.description]
        result = dict(zip(columns, row))
    cursor.close()
    conn.close()    
    return result

@app.route('/signup', methods=['POST'])
def signup():
    if request.method == 'POST':
        body = request.get_json()
        user_id = body['user_id']
        password = body['password']
        response = {}

        validate = Validate(user_id, password)
        flag, cause = validate.get_flag_cause()
        if flag:
            response['message'] = 'Account successfully created'
            response['user'] = {'user_id': user_id, 'nickname': user_id}
            # データベースにユーザー情報を登録
            conn = sqlite3.connect('database.db')
            cursor = conn.cursor()
            query = "INSERT INTO users (user_id, password, nickname) VALUES (?, ?, ?)"
            cursor.execute(query, (user_id, password, user_id))           
            conn.commit()
            cursor.close()
            conn.close()
            return jsonify(response), 200
        else:
            response['message'] = 'Account creation failed'
            response['cause'] = cause
            return jsonify(response), 400

def validate_basic_auth(request):
    auth_header = request.headers.get('Authorization')
    if auth_header:
        encoded_credentials = auth_header.split(' ')[-1]
        decoded_credentials = base64.b64decode(encoded_credentials).decode('utf-8')
        user_id, password = decoded_credentials.split(':')
        result = get_db_user(user_id) 
        if user_id == result['user_id'] and password == result['password'] :
            return True
    return False

@app.route('/users/<user_id>', methods=['GET'])
def get_user(user_id):
    response = {}
    result = get_db_user(user_id)    
    if validate_basic_auth(request):
        response['message'] = 'Authentication Failed'
        return jsonify(response), 401     
    if result:
        response['message'] = 'User detail by user id'
        response['user'] = {key: value for key, value in result.items() if value is not None and key != 'password'}
        return jsonify(response), 200             
    elif result is None:
        response['message'] = 'Not User found'
        return jsonify(response), 404


@app.route('/users/<user_id>', methods=['PATCH'])
def update_user(user_id):
    pass

@app.route('/close', methods=['POST'])
def delete_user():
    pass

if __name__ == "__main__":
    app.run(debug=True)
