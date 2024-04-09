mkdir -p data
touch "data/${1}.csv"
awk -v col="${1}" -F ',' '$1 == col {print $0}' data.csv > "data/${1}.csv"
