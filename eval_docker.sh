#!/bin/bash
if ! docker image inspect eval > /dev/null 2>&1; then
  echo "Image 'eval' not found locally. Building it..."
  docker build -t eval .
fi

docker run -it -w /app --entrypoint /bin/bash -v "$(pwd):/app" eval -c "chmod +x eval.sh && ./eval.sh \"$1\""
