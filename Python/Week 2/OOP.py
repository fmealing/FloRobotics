# This is part of a python class on Udemy
# Link: "https://www.udemy.com/course/python-the-complete-python-developer-course/?couponCode=KEEPLEARNING"



# ducks.py
class Wing(object):

    def __init__(self, ratio):
        self.ratio = ratio

    def fly(self):
        if self.ratio > 1:
            print("Wee, this is fun")
        elif self.ratio == 1:
            print("This is hard work, but I am flying")
        else:
            print("I think I'll just walk")


class Duck(object):

    def __init__(self):
        self._wing = Wing(1.8)

    def walk(self):
        print("Waddle, Waddle, Waddle")

    def swim(self):
        print("Come on in, the water is lovely")

    def quack(self):
        print("Quack quack")

    def fly(self):
        self._wing.fly()


class Penguin(object):

    def walk(self):
        print("Wadle, Waddle, I waddle too")

    def swim(self):
        print("Come on in, but it is a bit chilly this far South")

    def quack(self):
        print("Are you 'avin' a larf? I'm a penguin")


# def test_duck(duck):
#     duck.walk()
#     duck.swim()
#     duck.quack()


if __name__ == '__main__':
    donald = Duck()
    donald.fly()
    # test_duck(donald)

    # percy = Penguin()
    # test_duck(percy)
  
# enemy.py
# class Enemy:
class Enemy(object):

    def __init__(self, name="Enemy", hit_points=0, lives=1):
        self.name = name
        self.hit_points = hit_points
        self.lives = lives
        self.alive = True

    def take_damage(self, damage):
        remaining_points = self.hit_points - damage
        if remaining_points >= 0:
            self.hit_points = remaining_points
            print("I took {} points of damage and have {} left".format(damage, self.hit_points))
        else:
            self.lives -= 1
            if self.lives > 0:
                print("{0.name} lost a life".format(self))
            else:
                print("{0.name} is dead".format(self))
                self.alive = False

    def __str__(self):
        return "Name: {0.name}, Lives: {0.lives}, Hit-points: {0.hit_points}".format(self)


class Troll(Enemy):

    def __init__(self, name):
        # Enemy.__init__(self, name=name, lives=1, hit_points=23)
        # super(Troll, self).__init__(name=name, lives=1, hit_points=23)
        super().__init__(name=name, lives=1, hit_points=23)

    def grunt(self):
        print("Me {0.name}. {0.name} stomp you".format(self))

# html_doc.py
class Tag(object):

    def __init__(self, name, contents):
        self.start_tag = "<{}>".format(name)
        self.end_tag = "</{}>".format(name)
        self.contents = contents

    def __str__(self):
        return "{0.start_tag}{0.contents}{0.end_tag}".format(self)

    def display(self, file=None):
        print(self, file=file)


class DocType(Tag):

    def __init__(self):
        super().__init__('!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd"', "")
        self.end_tag = ""  # DOCTYPE doesn't have an end tag


class Head(Tag):

    def __init__(self):
        super().__init__('head', "")
        self._head_contents = []

    def add_tag(self, name, contents):
        new_tag = Tag(name, contents)
        self._head_contents.append(new_tag)

    def display(self, file=None):
        self.contents = ""  # Reset contents before adding tags
        for tag in self._head_contents:
            self.contents += str(tag)

        super().display(file=file)


class Body(Tag):
    def __init__(self):
        super().__init__('body', "")  # body contents will be built up separately
        self._body_contents = []

    def add_tag(self, name, contents):
        new_tag = Tag(name, contents)
        self._body_contents.append(new_tag)

    def display(self, file=None):
        self.contents = ""  # Reset contents before adding tags
        for tag in self._body_contents:
            self.contents += str(tag)

        super().display(file=file)


class HtmlDoc(object):

    def __init__(self):
        self._doc_type = DocType()
        self._head = Head()
        self._body = Body()

    def set_title(self, title):
        self._head.add_tag('title', title)

    def add_tag(self, name, contents):
        self._body.add_tag(name, contents)

    def display(self, file=None):
        self._doc_type.display(file=file)
        print("<html>", file=file)
        self._head.display(file=file)
        self._body.display(file=file)
        print("</html>", file=file)


if __name__ == "__main__":
    my_page = HtmlDoc()
    my_page.set_title("Document title")
    my_page.add_tag("h1", "Main heading")
    my_page.add_tag("h2", "sub-heading")
    my_page.add_tag("p", "This is a paragraph that will appear on the page")
    with open("test.html", "w") as test_doc:
        my_page.display(file=test_doc)

    new_body = Body()
    new_body.add_tag("h1", "Aggregation")
    new_body.add_tag("p", "Unlike <strong>composition</strong>, aggregation uses existing instances" 
                     " of objects to build up another object")
    new_body.add_tag("p", "The composed object doesn't actually own the objects that it's composed of"
                     " - if it's destroyed, those objects continue to exist.")

    # give our document new content by switching its body
    my_page._body = new_body
    with open("test2.html", "w") as test_doc:
        my_page.display(file=test_doc)

# main.py
from enemy import Enemy, Troll
from vampyre import Vampyre, VampyreKing

ugly_troll = Troll("Pug")
print("Ugly troll - {}".format(ugly_troll))

another_troll = Troll("Ug")
print("Another troll - {}".format(another_troll))

brother = Troll("Urg")
print(brother)

ugly_troll.take_damage(10)
another_troll.take_damage(1)
brother.take_damage(2)

ugly_troll.grunt()
another_troll.grunt()
brother.grunt()

monster = Enemy("Basic Enemy")
# monster.grunt()

# Vampyre Challenge
print("*" * 80)
countDracula = Vampyre("Count Dracula")
meInTheMorning = Vampyre("Me in the Morning")

print(countDracula)
print(meInTheMorning)

countDracula.take_damage(2)
meInTheMorning.take_damage(6)
print("*" * 80)
# End of challenge

# while countDracula.alive:
#     countDracula.take_damage(1)
#     print(countDracula)

countDracula.lives = 0
countDracula.hit_points = 1
print(countDracula)

print("*" * 80)
# Challenge
# Create a VampyreKing subclass of Vampyre
# A VampyreKing is going to be incredibly powerful, and any points of damage inflicted will be divided by 4
# VampyreKing objects will also start off with 140 hit points
# Test the new class by creating a new VampyreKing object and checking that it does start with 140
#   hit points and only takes a quarter of the damage inflicted
vampyreKing = VampyreKing("Vampyre King")
print(vampyreKing)
vampyreKing.take_damage(4)
print(vampyreKing)
print("*" * 80)

# player.py
"""
Challenge:
    - Modify the Player class so that thew players' scores are increased by one thousand
      every time their level increases by one.
    - So if they jump up two levels, they'll get a bonus of two
      thousand added to their score.
    - If the player drops back a level, they'll lose one thousand for each
      level they drop back. They can't go below level one, so your solution should preventing that from happening.
    - Use a property
"""


class Player(object):

    def __init__(self, name):
        self.name = name
        self._lives = 3
        self._level = 1
        self._score = 0

    def _get_lives(self):
        return self._lives

    def _set_lives(self, lives):
        if lives >= 0:
            self._lives = lives
        else:
            print("Lives cannot be negative")
            self._lives = 0

    # ----------------------------------------------------------- #
    # My attempt
    def _get_level(self):
        return self._level

    def _set_level(self, level):
        if level >= 1:
            level_difference = level - self._level
            self._score += level_difference * 1000
            self._level = level
        else:
            print("Level cannot be less than one")
            self._score = 1
    # ------------------------------------------------------------#
    lives = property(_get_lives, _set_lives)
    level = property(_get_level, _set_level)

    @property
    def score(self):
        return self._score

    @score.setter
    def score(self, score):
        self._score = score

    def __str__(self):
        return "Name: {0.name}, Lives: {0.lives}, Level: {0.level}, Score: {0.score}".format(self)

# vampyre.py
from enemy import Enemy
import random


class Vampyre(Enemy):
    def __init__(self, name):
        super().__init__(name=name, lives=3, hit_points=12)

    def dodges(self):
        if random.randint(1, 3) == 3:
            print("**** {0.name} dodges ****".format(self))
            return True
        else:
            return False

    # overwriting methods
    def take_damage(self, damage):
        if not self.dodges():
            super().take_damage(damage=damage)


class VampyreKing(Vampyre):

    def __init__(self, name):
        super().__init__(name=name)
        self.hit_points = 140

    def take_damage(self, damage):
        super().take_damage(damage // 4)
