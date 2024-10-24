class Animal:
    def __init__(
        self, color
    ):  # must be defined for all classes for which an object will be instantiated
        self.color = color  # instance variable

    def speak(self, text):
        print(text)

    def change_color(self, color):
        self.color = color
        self.speak("hi")

    def change_color(self):  # example of overloading - depending on arguments, the function change_color behaves differently
        self.color = "default"

    def __str__(self):  # default method called when printing an object of this class
        return "asdf"


class Legs4(Animal):  # Legs4 inherits from Animal
    def __init__(self, color):
        super().__init__(color)  # call the Animal constructor

    def speak(self):
        print("i have 4 legs")

    def change_color_2(self, color):
        self.color = color


class Legs2(Animal):

    num_legs = 2  # class variable

    def __init__(self, color, text):
        super().__init__(color)
        self.text = text

    def speak(self):
        print(self.text)

    def change_text(self, text):
        self.text = text


x = Animal("blue")
print(x.color)
x.speak("hello")

y = Legs4("black")
print(y.color)
# y.speak("hi")
y.speak()

z = Legs2("green", "hi")
# print(z.text)
z.speak()
z.change_text("hello")
z.speak()

a = Legs2("orange", "hi")
print(a.num_legs)
Legs2.num_legs = 5  # change for all classes
print(a.num_legs)
print(z.num_legs)
a.num_legs = 2  # this would change it only for a (essentially creates a new instance variable from the class variable)
print(a.num_legs)
print(z.num_legs)

x.change_color()
print(x.color)
x.color = ""
print(x.color)
print(x)
