#!/bin/bash

containerWasNotBuild() {
    [ $? -ne 0 ]
}

containerIsNotRunning() {
    [ $? -ne 0 ]
}

errorWhenCleaingUp() {
    [ $? -ne 0 ]
}

ubuntuVersion=$(grep VERSION_ID /etc/os-release | grep -oP '"\K[^"\047]+(?=["\047])')

echo "Building app for ubuntu version $ubuntuVersion"

echo "Building container for compilation of app"

docker build --build-arg TAG="$ubuntuVersion" -t buider_googleit:1.0 .

if containerWasNotBuild; then
    echo "Erro when building container"
    exit 1
fi

echo "Building the app"

docker run --name=builder_googleit buider_googleit:1.0

if containerIsNotRunning; then
    echo "Error when running container"
    exit 1
fi

echo "Cleaning up"

docker stop builder_googleit && docker rm builder_googleit

if errorWhenCleaingUp; then
    echo "Error when cleaing up container"
    exit 1
fi

exit 0