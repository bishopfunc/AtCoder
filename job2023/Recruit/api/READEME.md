curl -X POST http://localhost:5000/signup -H "Content-Type: application/json" -d '{
  "user_id": "TaroYamada",
  "password": "PaSSwd4TY"
}' 

curl -X GET http://localhost:5000/users/TaroYamada \
-H "Authorization: Basic PaSSwd4TY ==" \
