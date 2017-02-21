#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension


example_module = Extension('yurei',
                           sources=['libyurei.c', 'obj_loader/obj_loader.c' ],
                           )

setup (name = 'yurei',
       version = '0.1',
       author      = "Nicholas Oliveira",
       description = """Loader for 3d objects for the game""",
       ext_modules = [example_module],
       py_modules = ["yurei"],
       )
