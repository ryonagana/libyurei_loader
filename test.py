import os
import sys


try:
    import yurei
except ImportError as e:
    print(e)
    sys.exit(0)




model = yurei.load("model//eyeball.obj")
