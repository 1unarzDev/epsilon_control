import os
from glob import glob
from setuptools import find_packages, setup

package_name = "project_epsilon"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
    ],
    install_requires=[
        'setuptools',
        "numpy",
    ],
    zip_safe=True,
    author="Liam Bray",
    description="Project epsilon control package",
    license="GNU GPLv3",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            ...
        ],
    },
)
