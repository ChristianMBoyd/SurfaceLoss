# SurfaceLoss
This project contains the calculation for the surface loss function of a bounded, anisotropic electron gas ported from Mathematica to C++.

The basic linear algebra interface is handled by Eigen, which is included.  Matching Mathematica's C-compilation performance requires implementing MKL subroutines.  These files are not included.
The necessary Intel oneAPI .dll files are:
  1) the .dll files from the oneAPI/mkl redist folder,
  2) the libiomp5md.dll file from the oneAPI/compiler redist folder.



