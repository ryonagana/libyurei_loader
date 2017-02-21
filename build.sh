#!/bin/bash

#build SWIG
echo 'generating SWIG'
swig -python -py3 interfaces/libyurei_loader.i

#build python module via distutil
echo 'building python module'
python3 setup.py build_ext --inplace

mv interfaces/libyurei_loader.py test/libyurei_loader.py
mv *.so test/

python3 test/