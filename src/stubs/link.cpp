extern "C" void nninitStartup();

// must execute before anything else, including the swsplrs-linked `.init_array`
__attribute__((constructor(100))) void ctor() {
    nninitStartup();
}
