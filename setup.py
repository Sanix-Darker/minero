from setuptools import setup, Distribution


class BinaryDistribution(Distribution):
    def has_ext_modules(minero):
        return True

setup(
    name='minero',
    version='1.0',
    description='minero Library',
    package_data={
        'minero': ['./build/lib/minero.so'],
    },
    distclass=BinaryDistribution
)