void Functions::getNativeOffset(uint64_t nativeHash)
{
    auto mod = GetModuleHandleA("rage-scripting-five.dll");
    if (!mod)
    {
        return;
    }
 
    using GetHandlerFn = void* (*)(uint64_t);
    auto getHandler = (GetHandlerFn)GetProcAddress(mod, "?GetNativeHandler@scrEngine@rage@@SAP6AXPEAVscrNativeCallContext@2@@Z_K@Z");
    if (!getHandler)
    {
        return;
    }
 
    auto handlerAddr = (uint64_t)getHandler(nativeHash);
    uint64_t rva = handlerAddr - FiveM::BaseAddress;
 
    std::cout << "Offset: 0x" << std::hex << rva << std::endl;
}