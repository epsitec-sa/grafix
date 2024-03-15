#!/usr/bin/env python3
from pathlib import Path
import subprocess

source_dir = Path(__file__).parent
build_dir = source_dir / 'build'

subprocess.run(['cmake', '-S', source_dir, '-B', build_dir])
subprocess.run(['cmake', '--build', build_dir])
# subprocess.run(['cmake', '--install', build_dir])
