extern "C" void nninitStartup();

// must execute before anything else, including the swsplrs-linked `.init_array`
__attribute__((constructor)) void ctor() {
    nninitStartup();
}
