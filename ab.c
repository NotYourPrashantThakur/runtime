#include <string.h>

int checkString(const char* a2) {
    if (strstr(a2, "ob_normal") ||
        strstr(a2, "self_sys") ||
        strstr(a2, "stat_rpt") ||
        strstr(a2, "cal_cert_md5") ||
        strstr(a2, "9003_cert_md5") ||
        strstr(a2, "opcode_crash") ||
        strstr(a2, "crash_various_opcode") ||
        strstr(a2, "blur_exit") ||
        strstr(a2, "ob_local") ||
        strstr(a2, "tencent_tp") ||
        strstr(a2, "tplibc") ||
        strstr(a2, "frida_scan") ||
        strstr(a2, "reset") ||
        strstr(a2, "ace_rp") ||
        strstr(a2, "anti_") ||
        strstr(a2, "am_cnt") ||
        strstr(a2, "ce_bad") ||
        strstr(a2, "AntiStrip_Strategy") ||
        strstr(a2, "MrpcsActiveSig") ||
        strstr(a2, "sx_rel") ||
        strstr(a2, "qos_filt") ||
        strstr(a2, "comm_first") ||
        strstr(a2, "sc_dlp") ||
        strstr(a2, "scan_x86") ||
        strstr(a2, "ms_va") ||
        strstr(a2, "mrpcs_lib") ||
        strstr(a2, "builtin") ||
        strstr(a2, "scan1") ||
        strstr(a2, "info") ||
        strstr(a2, "#T#E#R#S#I#G#START#")) {
        return 0;
    }
    return 1;
}
