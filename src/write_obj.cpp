#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  
  std::ofstream obj_file;
  obj_file.open(filename);

  //List of geometric vertices
  for (int i = 0; i< V.rows(); i++){
    std::string line = "v " + V(i,0) + " " + V(i,1) + " " + V(i,2) + "\n";
    obj_file << line;
  }

  //List of texture coordinates
  for (int i = 0; i< UV.rows(); i++){
    std::string line = "vt " + UV(i,0) + " " + UV(i,1)  + "\n";
    obj_file << line;
  }

  //List of vertex normals
  for (int i = 0; i< NV.rows(); i++){
    std::string line = "vn " + NV(i,0) + " " + NV(i,1) + " " + NV(i,2) + "\n";
    obj_file << line;
  }

  //Polygonal face element
  //f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3
  for (int i = 0; i< F.rows(); i++){
    std::string line = "f";
    for (int j  0; j< F.cols(); j++){
      line = line + " " + (F(i,j)+1) + "/" + (UV(i,j)+1) + "/" + (NV(i,j)+1);
    }
    line +="\n";
    obj_file << line;
  }
  
  obj_file.close();

  ////////////////////////////////////////////////////////////////////////////
  return false;
}
