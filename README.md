# Sample code for the blog article *Test-driving the MCP2515 CAN Controller (Part 1)*
[Link to blog](https://deardevices.com/2017/10/08/test-driving-the-mcp2515-can-controller-part-1/)

First pull in googletest and googlemock (needs to be done only once):
```
$ git submodule update --init
```

Then start the build and run all unit tests:
```
$ make && ./test
```
