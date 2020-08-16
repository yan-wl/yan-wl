#!/bin/bash

HTML=$(cat)
CSS=".grid{display:grid;grid-template-columns:repeat(23,30px);grid-template-rows:repeat(10,30px);}.white-cell{border-style:solid;border-width:1px;background-color:white;border-color:black;}.black-cell{border-style:solid;border-width:1px;background-color:black;border-color:black;}"

curl -X POST https://hcti.io/v1/image -u "$HCTI_USER_ID:$HCTI_API_KEY" -d html="<div class='grid'>$HTML</div>" -d css="$CSS" | \
python -c "import json, sys; obj = json.load(sys.stdin); print(obj['url'])" | \
{ URL=$(cat); echo "![grid]($URL)"; }