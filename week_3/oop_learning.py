class Animal:
    def __init__(self, color):
        self.color = color
    
    def speak(self, text):
        print(text)

    def change_color(self, color):
        self.color = color
        self.speak("hi")

    def __str__(self):
        return "asdf"


class Legs4(Animal):
    def __init__(self, color):
        super().__init__(color)

    def speak(self):
        print("i have 4 legs")

    def change_color_2(self, color):
        self.color = color

class Legs2(Animal):
    
    num_legs = 2

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
# a.num_legs = 5
# print(a.num_legs)
# print(z.num_legs)

# x.change_color()
# x.color = ""
print(x)
