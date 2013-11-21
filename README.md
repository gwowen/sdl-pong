sdl-pong
========

An old SDL 1.2 Pong game I made a while back. I thought I lost it when my old laptop died... but it turns out it was still 
there in the cloud and I downloaded it this summer and took another look. Happy times!

It's kind of obsolete now given the arrival of SDL2, but it's still a (mostly) complete game that features a state manager
and a basic component/entity system for the balls and bat. I've cleaned it up a bit and changed the build system to CMake.
I did have a fully complete version somewhere, but it's been misplaced. When I can get around to it I'll probably finish it
off AGAIN, but right now I'm taking the attitude "one man's junk is another's treasure" and putting it up here.

To build it, create a subdirectory called "build", then run "cmake .." and then "make". You'll need the main SDL development
libraries, as well as SDL_image.
