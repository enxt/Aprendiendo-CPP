SUBDIRS = Cuestion1.1 Cuestion1.2 Cuestion1.3 Cuestion1.4 Cuestion1.5 Cuestion2.1 Cuestion2.2 Cuestion2.3 Cuestion2.4 Cuestion2.5 Cuestion3.1 Cuestion3.2 Cuestion3.3 Cuestion3.4 Cuestion3.5
CLEANSUBDIRS = $(SUBDIRS:%=clean-%)
TARSUBDIRS = $(SUBDIRS:%=tar-%)

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

clean: $(CLEANSUBDIRS)
$(CLEANSUBDIRS):
	$(MAKE) -C $(@:clean-%=%) clean
	rm -f $(@:clean-%=%).tar.gz
	
prepare: clean $(TARSUBDIRS)
$(TARSUBDIRS):
	cd $(@:tar-%=%) && tar --exclude README.md --exclude CMakeLists.txt -cvzf ../$(@:tar-%=%).tar.gz *
