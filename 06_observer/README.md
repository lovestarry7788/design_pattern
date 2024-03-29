### 观察者模式的基本概念
观察者模式是行为型模式。定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。

### 观察者模式的结构组成
Subject：目标类，用一个列表来记录当前目标对象有哪些观察者对象。
Object：观察者类，是所有观察者对象的父类；它为所有的观察者对象都定义了一个名为update的方法（也叫成员函数）。当目标对象的状态改变时，它就是通过调用它的所有观察者对象的update方法来通知它们的。

### 观察者模式的优点与缺点
优点：1、观察者与被观察者是抽象耦合的。2、建立一套触发机制。
缺点：1、如果一个被观察者对象有很多的直接和间接的观察者的话，将所有的观察者都通知到会花费很多时间。
