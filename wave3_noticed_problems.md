# NOTICE #
THIS DOCUMENT IS FOR REPORTING ISSUES WITH THE WAVE3.PY PROGRAM ITSELF TO THE WAVE3.PY DEVELOPER AGENT SUCH AS COMMANDS FUNCTIONING INCORRECTLY, MISSING FUNCTIONALITY, NEEDED IMPROVEMENTS, ETC. IF YOU FIND ANY FALSE OR INCORRECT DATA IN WAVE3.PY THAT SHOULD BE REPORTED TO E:\NTK\GhidraBridge\source-3\project-documentation\wave3_data_issues.md INSTEAD. IT SHOULD FOLLOW THE SAME FORMAT AS THIS DOCUMENT.

# Wave3 Program Noticed Problems

## Core Program Issues

No active core program issues currently.

## Non-Issues / Usage Notes

- Parallel fanout with very short caller timeouts can still abandon the caller before queued read-only commands complete. Use serial calls, longer caller timeouts, or `python wave3d.py debug profile command --health -- <command>` for development verification. Previously reported UserLook, DAT, Palette, ResourceLayoutTable, and ImageLib examples now complete cleanly when run serially or with a reasonable timeout.
- 2026-05-24 documentation pass note: running `show project-status --summary` and `list file --detailed` in parallel with a 30 second caller timeout produced `Wave3ClientAbandonedError` after the caller timed out. `wave3-status.md` still reported `OPERATIONAL`. Treat this as the known short-timeout/fanout usage caveat unless it reproduces serially with a longer timeout.
- Full `debug restart cache prewave` is intentionally a cold restart of prewave, wave2, wave3 cache, and main. It was re-tested on 2026-05-24 and completed with health OK, but it took several minutes; use a long caller timeout when deliberately restarting the full cache stack.
