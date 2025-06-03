if [ -n "$(./refstr | grep -E '(a?){15}a')" ]
then
    echo "Test passed"
    exit 0
else
    echo "Test failed"
    exit 1
fi
