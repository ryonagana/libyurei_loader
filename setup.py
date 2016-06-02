#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension


example_module = Extension('_libyurei_loader',
                           sources=['interfaces/libyurei_loader_wrap.c',
                                     'obj_loader.c',
                               ],
                           )

setup (name = 'yurei_loader',
       version = '0.1',
       author      = "Nicholas Oliveira",
       description = """Loader for 3d objects for the game""",
       ext_modules = [example_module],
       py_modules = ["yurei_loader"],
       )
