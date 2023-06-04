#include <stdio.h>
#include <string.h>

int main() {
    const char* ob_normal = "ob_normal";
    const char* self_sys = "self_sys";
    const char* stat_rpt = "stat_rpt";
    const char* cal_cert_md5 = "cal_cert_md5";
    const char* cert_md5 = "9003_cert_md5";
    const char* opcode_crash = "opcode_crash";
    const char* crash_various_opcode = "crash_various_opcode";
    const char* blur_exit = "blur_exit";
    const char* ob_local = "ob_local";
    const char* tencent_tp = "tencent_tp";
    const char* tplibc = "tplibc";
    const char* frida_scan = "frida_scan";
    const char* reset = "reset";
    const char* ace_rp = "ace_rp";
    const char* anti_ = "anti_";
    const char* am_cnt = "am_cnt";
    const char* ce_bad = "ce_bad";
    const char* AntiStrip_Strategy = "AntiStrip_Strategy";
    const char* MrpcsActiveSig = "MrpcsActiveSig";
    const char* sx_rel = "sx_rel";
    const char* qos_filt = "qos_filt";
    const char* comm_first = "comm_first";
    const char* sc_dlp = "sc_dlp";
    const char* scan_x86 = "scan_x86";
    const char* ms_va = "ms_va";
    const char* mrpcs_lib = "mrpcs_lib";
    const char* builtin = "builtin";
    const char* scan1 = "scan1";
    const char* info = "info";
    const char* TERSIG = "#T#E#R#S#I#G#START#";

    const char* a2 = "input_string_to_check";

    if (strstr(a2, ob_normal) ||
        strstr(a2, self_sys) ||
        strstr(a2, stat_rpt) ||
        strstr(a2, cal_cert_md5) ||
        strstr(a2, cert_md5) ||
        strstr(a2, opcode_crash) ||
        strstr(a2, crash_various_opcode) ||
        strstr(a2, blur_exit) ||
        strstr(a2, ob_local) ||
        strstr(a2, tencent_tp) ||
        strstr(a2, tplibc) ||
        strstr(a2, frida_scan) ||
        strstr(a2, reset) ||
        strstr(a2, ace_rp) ||
        strstr(a2, anti_) ||
        strstr(a2, am_cnt) ||
        strstr(a2, ce_bad) ||
        strstr(a2, AntiStrip_Strategy) ||
        strstr(a2, MrpcsActiveSig) ||
        strstr(a2, sx_rel) ||
        strstr(a2, qos_filt) ||
        strstr(a2, comm_first) ||
        strstr(a2, sc_dlp) ||
        strstr(a2, scan_x86) ||
        strstr(a2, ms_va) ||
        strstr(a2, mrpcs_lib) ||
        strstr(a2, builtin) ||
        strstr(a2, scan1) ||
        strstr(a2, info) ||
        strstr(a2, TERSIG))
    {
        return 0;
    }

    // Your code continues here...

    return 0;
}
