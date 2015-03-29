SUBDIRS = Cuestion1.1 Cuestion1.2 Cuestion1.3 Cuestion1.4 Cuestion1.5 Cuestion2.1 Cuestion2.2
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
	cd $(@:tar-%=%) && tar cvfz ../$(@:tar-%=%).tar.gz * --exclude Readme
