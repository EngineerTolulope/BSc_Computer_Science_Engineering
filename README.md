# Bachelor of Science in Computer Science Engineering
The repository contains some of the course work and projects I completed during my bachelor's degree program in Hungary, which ended in January 2018.
I had the opportunity to work with a variety of programming languages, including C/C++, Java, Python, and MATLAB. 

## Summary of the Thesis Documentation
### Thesis Topic - Visual Representation of Simple Simulated Processes

This thesis was written in the programming language C. This research project is an excellent illustration of the application of random walk theory; first, we needed to understand the concept of bmp files, how they work, the format in which they are stored, how they are created, and how they can be manipulated. It was critical to familiarize ourselves with its concepts in order to have the technical know-how necessary to create and manipulate these files in the subsequent implementation. The images below demonstrate some of the manipulations performed on the bmp files before and after.
  
![image (5)](https://user-images.githubusercontent.com/94204398/143798486-74adcefc-1a6a-419c-b370-3503231a7590.png)

  After we had mastered the concepts, we needed to implement the random walk, in which a given number of walkers move randomly, the visible part of the walkers is a fixed length, and when any of the walkers reaches an edge, it exits from the opposite side. All required values are read from a parameter file, allowing for easy manipulation without modifying the source code. Each walker is composed of squares with a fixed length for all of them; this is because representing only one pixel proved to be too small; therefore, squares with a length of 2S+1 are used instead; snapshots are taken at various time simulations. The images below illustrate the motion of 10, 20, and 30 particles through time.
 
 <p align="center">
  <img width="250" src="https://user-images.githubusercontent.com/94204398/143799349-55ce01ae-0787-4aaa-a2a8-0f7c43c47125.gif" alt="Material Bread logo">  <img width="250" src="https://user-images.githubusercontent.com/94204398/143799468-d9d61d6b-0b5f-4260-8989-50df59008d67.gif" alt="Material Bread logo">  <img width="250" src="https://user-images.githubusercontent.com/94204398/143799540-11143a55-281d-4cb6-8200-b8f899d52fa0.gif" alt="Material Bread logo">
</p>

  Diffusion limited aggregation is a process in which particles that follow the random walk cluster together to form structures; we can obtain nice and beautiful images by coagulating these particles. In the two-dimensional representation, a sticky base line is drawn on the x axis; particles are introduced into the system at a dynamic distance; particles begin to move randomly; if a particle exceeds an upper set limit, it dies; a new particle is introduced into the system.

  If the particle reaches any of the x axis edges, it exits from the opposite side; if the particle contacts the base line or any of the previous particles in the list, it becomes stuck; if the particle's y coordinate is greater than the list's maximum height, this becomes the new maximum; the particle is added to the list; another particle is initialized until the desired number of particles is reached. Finally, we obtain a lovely tree-like image created by the cluster of particles inserted into the system; the color of each particle is dependent on the time it was added to the list. The figure below illustrates the outcome of this simulation.
  
  <p align="center">
  <img  height="300" src="https://user-images.githubusercontent.com/94204398/143800421-1f511a34-3e3c-4825-997c-268a6970e7b8.png" alt="Material Bread logo">
  </p>

  The concept is identical in the three-dimensional representation, but there are six directions for movement rather than four in the two-dimensional representation, and there are also six probabilities. To demonstrate the results of the 3d implementation in a simple manner, the concept of ray tracing is used in conjunction with the pov-ray application. Initially, a square shape with a fixed length is created on the x-z axis; particles are initialized at a dynamic height above the sticky square; if a particle exceeds the upper limit, it dies and a new particle is initialized; and if a particle reaches one of the x or z axis edges, it exits from the opposite edge.
   
  <p align="center">
  <img  src="https://user-images.githubusercontent.com/94204398/143800780-46a4391e-fb11-43fc-a60e-9065834cb5cd.gif" alt="Material Bread logo">
  </p>

  During the random movement of the particle, if it comes into contact with the sticky bottom square or any previous particle in the list, it becomes stuck; if the y-coordinate of this particle is greater than the list's maximum height, it becomes the new maximum; a new particle is initialized; and the process is repeated until the desired number of particles is reached. At a multiple of a specified number, a new pov file is created and all necessary parameters are set; this creates a snapshot of the particles in the list based on their coordinates at that time step. Finally, we obtain lovely/beautiful sets of images created by the implementation and capable of being evaluated using the pov-ray application. The figure above illustrates the growth of a tree-like structure as a result of random particle movement.
  
  Random walk theory is a critical concept that can be applied to our daily lives, career choices, the stock market, drunken behavior, the prediction of a fair die, and gambling. Additional applications of the random walk theory include physics, financial economics, computer networks, computer science, medicine, brain research, and physiology, among others.


