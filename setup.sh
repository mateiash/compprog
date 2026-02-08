if [ "$#" -ne 2 ]; then
    echo "Bad args"
    exit 0
fi

DIR="$(dirname "$(realpath $0)")"
cp $DIR/run.sh $1

cp $DIR/$2/template.cpp $1
cp --update=none $1/template.cpp $1/main.cpp
rm $1/template.cpp
