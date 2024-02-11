times = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
initial_velocity = 5
gravity = 9.81

for time in times:
    vert_position = initial_velocity * time - (0.5 * gravity * time**2)

    print(time, vert_position)
