if ln text text.lock
  then
  for i in $(seq 1 100);
  do
    LAST="$(tail -1 text)"
    expr $LAST + 1 >> text
  done
  rm text.lock
fi
