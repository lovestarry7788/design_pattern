c++ 设计模式实例代码
### 创建型模式
<hr>

### 常见的面试问题
#### 1. 简单介绍一下软件开发原则？

#### 2. 设计模式如何分类？

创建型模式：创建对象的同时隐藏创建逻辑，不使用new直接实例化对象。该模式包含简单工厂模式、工厂方法模式、抽象工厂模式、单例模式等。

结构型模式：通过类和接口间的继承和引用实现创建复杂结构的对象。该模式包含代理模式。

行为型模式：通过类之间的不同通信方式实现不同行为。如策略模式、观察者模式。


#### 3. 单例模式有什么优缺点？什么时候使用它？

#### 4. 代理模式有什么优缺点？什么时候使用它？
代理模式分类：
静态代理：代理类和委托类的关系在运行前就确定了。
动态代理：代理类和委托类的关系在运行时确定。

代理模式使用的场景：
保护目标对象：客户端 只与 代理类进行交互，不清楚 目标对象 的细节。
增强目标对象：对 目标对象的功能 进行增强。

代理模式的优点：
1. 分离目标对象，降低耦合。
2. 保护、增强目标对象。

代理模式的缺点：
1. 性能降低，请求处理速度变慢。


#### 5. 策略模式有什么优缺点？什么时候使用它？

#### 6. 简单工厂、工厂方法和抽象工厂方法有什么区别
* 简单工厂：只有唯一工厂，一个产品接口/抽象类，根据简单工厂中的方法来创建具体产品对象。适用于产品较少，几乎不扩展的情景。
* 工厂方法：有多个工厂（抽象工厂+多个具体工厂），一个产品接口/抽象类，根据继承抽象工厂中的方法来多态创建具体产品对象。适用于一个类型的多个产品。
* 抽象工厂：有多个工厂（抽象工厂+多个具体工厂），多个产品接口/抽象类，对产品子类进行分组，根据继承抽象工厂中的方法来多态创建同组的不同具体产品对象。适用于多个类型的多个产品。


* [简单工厂模式（Simple Factory）](https://github.com/lovestarry7788/design_pattern/tree/master/00_simple_factory)
* [工厂方法模式（Factory Method）](https://github.com/lovestarry7788/design_pattern/tree/master/01_factory_method)
* [抽象工厂模式（Abstract Factory）](https://github.com/lovestarry7788/design_pattern/tree/master/02_abstract_method)
* [单例模式（Singleton) ](https://github.com/lovestarry7788/design_pattern/tree/master/03_singleton)
* [代理模式（Proxy) ](https://github.com/lovestarry7788/design_pattern/tree/master/04_proxy)
* [策略模式（Strategy) ](https://github.com/lovestarry7788/design_pattern/tree/master/05_strategy)
* [观察者模式（Observer）](https://github.com/lovestarry7788/design_pattern/tree/master/06_observer)