pip3 install wheel
pip3 uninstall ./dist/*
rm -rf ./dist/*
python3 setup.py bdist_wheel
pip3 install ./dist/*