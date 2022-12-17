install:
	pip install .

uninstall:
	pip uninstall nc

clean:
	$(RM) -rf build
	$(RM) -rf nc.egg-info
