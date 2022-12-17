from setuptools import setup, Extension
from Cython.Distutils import build_ext
import numpy as np

NAME = "nc"
VERSION = "0.0.1"
DESC = "Eeee"
REQUIRES = ["numpy", "cython"]
AUTHOR = "Jørgen Henriksen"
SRC_DIR = "nc"
PACKAGES = [SRC_DIR]

ext_1 = Extension(SRC_DIR + ".experimental_mapper", 
        [SRC_DIR + "/experimental_mapper.pyx"], 
        libraries=[], 
        include_dirs=[np.get_include()])

EXTENSIONS = [ext_1]

if __name__ == "__main__":
    setup(install_requires=REQUIRES, 
            packages=PACKAGES,
            zip_safe=False,
            name=NAME,
            version=VERSION,
            description=DESC,
            author=AUTHOR,
            cmdclass={"build_ext": build_ext},
            ext_modules=EXTENSIONS)
