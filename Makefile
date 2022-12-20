.PHONY: clean install uninstall

install: clean
	pip install .

uninstall: clean
	pip uninstall nc

clean:
	$(RM) -rf build
	$(RM) -rf nc.egg-info
