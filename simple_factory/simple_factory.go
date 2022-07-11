package simple_factory

type API interface {
	Say(name string) string
}

func NewAPI(x int) API {
	if x == 1 {
		return hiAPI{}
	} else if x == 2 {
		return helloAPI{}
	}
	return nil
}

type hiAPI struct{}
type helloAPI struct{}

func (hiAPI) Say(name string) string {
	return "Hi, " + name
}

func (helloAPI) Say(name string) string {
	return "Hello, " + name
}
