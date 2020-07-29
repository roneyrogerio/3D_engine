

**This is not a library for use in production, its purpose is entirely didactic!**

An example usage program has been built and is available at # **[cub3D](https://github.com/roneyrogerio/cub3D)**

The test can be done with the following commands:
```sh
git clone https://github.com/roneyrogerio/cub3D.git
cd cub3D && make
./cub3D c3d.cub
```

![test](https://raw.githubusercontent.com/roneyrogerio/cub3D/master/print.gif)


## Functions

|Function  | Description |
|--|--|
|[ngn_init](/ngn_init.c)| Starts the engine with a config file and returns a void pointer that can be used with ***ngn_camera***, ***ngn_mini_map***, ***ngn_get_window_size***, ***ngn_set_window_size***, ***ngn_set_walk***, ***ngn_set_turn***, ***ngn_movement_update***, ***ngn_destroy***.|
|[ngn_camera](/ngn_camera.c)|Draw the 3D image using a function pointer passed as an argument.|
|[ngn_mini_map](/ngn_mini_map.c)|Draw the mini map using a function pointer passed as an argument.|
|[ngn_get_window_size](/ngn_get_window_size.c)|Get width and height.|
|[ngn_set_window_size](/ngn_set_window_size.c)|Set the width and height.|
|[ngn_movement_update](/ngn_set_movement.c)|Updates the player's position on the map when any movement is set with ***ngn_set_walk*** or ***ngn_set_turn***.|
|[ngn_set_walk](/ngn_set_movement.c)|Sets the player to move forward or backward.|
|[ngn_set_turn](/ngn_set_movement.c)|Sets the player to rotate right or left.|
|[ngn_strerror](/ngn_strerror.c)|When a function returns an error the error code is placed in the variable **g_ngnerr**, this function gets the error message string.|
|[ngn_destroy](/ngn_destroy.c)|Free the allocated memory with ***ngn_init***.|
