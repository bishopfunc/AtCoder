list=$(find ./data/* -type f -name "*.csv")
# echo "${list}"
for item in ${list}
do
  date=$(basename "${item}" | sed 's/\.[^.]*$//')
  awk -F ',' -v date="${date}" '{sum += $3} END {print date ": " int(sum * 0.8);}' < "${item}"
done
