#!/bin/sh
lineCount=`wc -l $1 | cut -d ' ' -f1`
if [ $lineCount -ge 3 ]; then
    word=`head -3 $1 | tail -1  | cut -d ' ' -f1 `
    echo "The ist word of third line is : ${word}"
else
    echo "No sufficient lines."
fi
