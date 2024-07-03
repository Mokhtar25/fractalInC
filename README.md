# fractalInC


My project is a Fractal.
<!-- ### Video Demo:  <[fractal in C](https://youtu.be/nPjcbpd7Zk0)> -->
#### Description:

Fractals are interesting  geometric shapes that exhibit repeating shapes at different scales. They are often generated by iterative mathematical processes. One of the most famous examples is the Mandelbrot set, and it's the one I'm Implementing in my program. The Mandelbrot set is defined by iterating a simple equation Zn+1 = Z^2n + C Where C is a complex number.

> In mathematics, a fractal is a geometric shape containing detailed structure at arbitrarily small scales, usually having a fractal dimension strictly exceeding the topological dimension.

So therefore I got the idea to make something like that in C. I started by looking at the mathematical side of the set and getting the equations and how it works. And then started looking for a good library to use to draw the pixels to the screen. I found Raylib to be the easiest and it offers a lot of features and it seemed to have a big community behind it. I also explored the examples they gave and I started my project. And the reason I decided to make the program in C is because of the performance abilities that the language provides and the low-level control. And I generally enjoy programming in C.

The program has some constant values that you can change like moveSpeed to control how fast you move in and out the shape when clicking the left button of the mouse to zoom in and the right button to zoom out. Also a buffer that gives a buffer when moving the shape with the mouse. It helps the shape stay in place when no movement is wanted generally in the middle of the window. Feel free to play with these Numbers to increase the Speed or slowing it down.

There are some macros as well at the head of the page. You can increase the width to make the window wider or the height to make the window taller. And there is the MAX_ITERATION. That controls how deep you can go inside the shape and how detailed it is. You can make increase to make it more detailed and to dive deeper but that would come at the cost of performance and it will consume a lot of processing power. 


##A requirements 
Raylib must be installed to compile.

##A Changing color 
You can easily change the color by editing the (r,g,b) values at the end of the page. And you can also add some interesting color patterns when using a random number generator. That is also add but commented out. So it's easily implemented.

###A The Included files
1-project.c is the main file and is compiled to make the program.
2-Makefile is to easily compile the Program with the command `make project`
3-librarylib.a is the Raylib dependencies that are required to compile the program
4-README.md is description to the project
5-project is just the compiled program you can run it by `./project`

###A How it works

Firstly by initializing  a window with a specific width and height. And then using loops to loop through every pixel and drawing a different color on  it using the Mandelbrot set equations. And then drawing the pixel on the screen depending on the iteration with black or a different color. 

Adding zoom and control. To add zoom to the project we have to modify the set to the new zoomed window. And by adding the zoomed window width and height to the mandelbrot equation you can re-render the pixels everytime you zoom in. When implementing the controls to move left and right I used the mouse coordinates and depending on the area the shape moves left or right, up or down.

The MAX_ITERATION affects the performance by how deep the shape is rendered and when implementing a high value it's going to require more power from the computer. From my testing I recommend something between 120-50.  Tweaking the fps counter could lead to improving the performance as well. By rendering less frames and consuming less power.

mandelbrotRect is a triangle that contains some Mandelbrot sets points to start the shape with. And this what enables the zoom ability because when zooming this edits the height and with values  and therefore making the shape render into this new rectangle. And it is also used to move around the shape by modifying the x and y values when moving to control where the rectangle is located and therefore moving around the shape.








 
