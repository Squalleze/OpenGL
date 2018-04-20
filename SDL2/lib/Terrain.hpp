#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#define GL3_PROTOTYPES 1
#include <GL/glew.h>

class Terrain {
  private:
    int w; //Width
    int l; //Length
    float** hs; //Heights
    Vec3f** normals;
    bool computedNormals; //Whether normals is up-to-date
    Terrain(int w2, int l2) {
      w = w2;
      l = l2;
      
      hs = new float*[l];
      for(int i = 0; i < l; i++) {
          hs[i] = new float[w];
      }
      
      normals = new Vec3f*[l];
      for(int i = 0; i < l; i++) {
          normals[i] = new Vec3f[w];
      }
      
      computedNormals = false;
    }
    ~Terrain() {
        for(int i = 0; i < l; i++) {
            delete[] hs[i];
        }
        delete[] hs;
        
        for(int i = 0; i < l; i++) {
            delete[] normals[i];
        }
        delete[] normals;
    }
    int width() {
        return w;
    }
    
    int length() {
        return l;
    }
    //Sets the height at (x, z) to y
    void setHeight(int x, int z, float y) {
        hs[z][x] = y;
        computedNormals = false;
    }
    
    //Returns the height at (x, z)
    float getHeight(int x, int z) {
        return hs[z][x];
    }
    //Computes the normals, if they haven't been computed yet
    void computeNormals() {
        //...
    }
    //Returns the normal at (x, z)
    Vec3f getNormal(int x, int z) {
        if (!computedNormals) {
            computeNormals();
        }
        return normals[z][x];
    }
};