#!/user/bin/env python3
"""
This module calculates propeties of a circle
"""

PI = 3.14

class Circle:
    """A class to represent the circle.

        ..........
    Attributes
    ----------
    radius: str
        the radius of the Circle

    Methods
    -------
    area():
        Prints the Circle's area.

    perimeter():
        Prints the Circle's perimeter.
    """
    def __init__(self,radius:int) -> None:
        """
        Constructs all the necessary attributes for the Circle object.
        
        Parameters
        ----------
            radius: str
                the radius of the Circle
        """
        assert radius > 0 , \
            "circle radius must be a positive number"
        self.radius = radius

    def area(self) -> str:
        '''calculate the area of the circle, return the result'''
        return PI * self.radius**2

    def perimeter(self) -> str:
        '''calculate the perimeter of the circle, return the result'''
        return 2 * PI * self.radius

    def __repr__(self):
        return f"{self.__class__.__name__}(radius={self.radius})"
