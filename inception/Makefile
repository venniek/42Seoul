all:
	docker-compose -f ./srcs/docker-compose.yml up

down:
	docker-compose -f ./srcs/docker-compose.yml down

re: clean all

clean:
	docker-compose -f ./srcs/docker-compose.yml down --rmi all --volumes

.PHONY: all re down clean
