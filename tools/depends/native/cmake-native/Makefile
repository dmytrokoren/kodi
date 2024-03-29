include ../../Makefile.include
PLATFORM=$(NATIVEPLATFORM)
DEPS= ../../Makefile.include.in Makefile

APPNAME=cmake
VERSION=3.6.2
SOURCE=$(APPNAME)-$(VERSION)
ARCHIVE=$(SOURCE).tar.gz

# configuration settings

SETENV=CC=$(CC_FOR_BUILD) CXX=$(CXX_FOR_BUILD) LD=$(LD_FOR_BUILD) CFLAGS="$(NATIVE_CFLAGS) -Werror=unguarded-availability-new" \
	CXXFLAGS="$(NATIVE_CXXFLAGS) -Werror=unguarded-availability-new" LDFLAGS="$(NATIVE_LDFLAGS) -Wl,-no_weak_imports"

ifeq ($(NATIVE_OS), osx)
  SETENV+=SDKROOT=$(shell xcrun --show-sdk-path)
endif

CONFIGURE=./bootstrap --prefix=$(NATIVEPREFIX) --system-curl

APP=$(PLATFORM)/bin/$(APPNAME)

CLEAN_FILES=$(ARCHIVE) $(PLATFORM)

all: .installed-$(PLATFORM)

$(TARBALLS_LOCATION)/$(ARCHIVE):
	cd $(TARBALLS_LOCATION); $(RETRIEVE_TOOL) $(RETRIEVE_TOOL_FLAGS) $(BASE_URL)/$(ARCHIVE)

$(PLATFORM): $(TARBALLS_LOCATION)/$(ARCHIVE) $(DEPS)
	-rm -rf $(PLATFORM)/*; mkdir -p $(PLATFORM)
	cd $(PLATFORM); $(ARCHIVE_TOOL) $(ARCHIVE_TOOL_FLAGS) $(TARBALLS_LOCATION)/$(ARCHIVE)
	cd $(PLATFORM); sed -ie "s/CMAKE_OSX_DEPLOYMENT_TARGET/CMAKE_OSX_DEPLOYMENT_TARGET_FOOO/" Modules/Platform/Darwin-Initialize.cmake
	cd $(PLATFORM); patch -p0 < ../futimens.patch
	cd $(PLATFORM); $(SETENV) $(CONFIGURE)

$(APP): $(PLATFORM)
	$(MAKE) -C $(PLATFORM)
	touch $@

.installed-$(PLATFORM): $(APP)
	$(MAKE) -C $(PLATFORM) install
	touch $@

clean:
	$(MAKE) -C $(PLATFORM) clean
	rm -f .installed-$(PLATFORM)

distclean::
	rm -rf $(PLATFORM) .installed-$(PLATFORM)

