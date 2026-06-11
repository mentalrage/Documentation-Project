*** UID:0000UA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CurlWriteCallback 0x00581B80

## Status

- Disposition: project-owned libcurl callback helper
- Address range: `0x00581b80-0x00581ce6`
- Likely source module: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Autogen parent: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Exact memory range: [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md)
- Parent memory range: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- Confidence: strong for ownership and behavior; medium for final public signature naming.

## Behavior

This helper is the write callback passed to libcurl by `StartupWindow::RunUpdateCheck`. It appends each received text chunk into a 24-byte ANSI small-string buffer used by the startup updater, preserving the same inline/heap storage convention as nearby string helpers.

The decompiled body:

- Computes the incoming append length with `strlen(source)`.
- Reads the current string length from buffer offset `+0x10` and capacity from `+0x14`.
- Grows capacity when needed with the common `requiredLength | 0x0f` alignment policy and half-capacity growth check.
- Copies old data and incoming bytes with `memmove`, null terminates the destination, and frees the old heap buffer when the prior capacity was heap-backed.
- Returns `elementSize * elementCount`, matching the count libcurl expects from a write callback.

## IDA Evidence

Checked on 2026-05-24:

- `lookup_funcs 0x00581b80` confirms a real function at `0x00581b80` with size `0x166`.
- `xrefs_to 0x00581b80` reports data references at `0x00580c6f` and `0x00580efb`, both inside `StartupWindow::RunUpdateCheck`. These are callback-pointer setup sites rather than ordinary direct calls.
- IDA reports no normal function callers for `0x00581b80`, which is expected for a function pointer callback.
- `decompile 0x00581b80` shows `int __cdecl sub_581B80(const char *Src, int a2, int a3, void **a4)`, calls `strlen(Src)`, appends into an SSO-like buffer, and returns `a3 * a2`.

Rechecked on 2026-05-25:

- `lookup_funcs 0x00581b80` still reports a real function with size `0x166`.
- `xrefs_to 0x00581b80` still reports only data refs at `0x00580c6f` and `0x00580efb`, both inside `StartupWindow::RunUpdateCheck`.
- Raw disassembly at both setup sites pushes `offset sub_581B80`, option `0x4e2b`, and the curl handle before calling `curl_easy_setopt`.

Rechecked on 2026-05-26:

- `lookup_funcs` still reports `sub_581B80` at `0x00581b80` with size `0x166`.
- `xrefs_to 0x00581b80` still reports only data refs at `0x00580c6f` and `0x00580efb`, both inside `StartupWindow::RunUpdateCheck`; `callers 0x00581b80` remains empty.
- The adjacent parse/string helpers `0x00581cf0`, `0x00581e40`, and `0x00581f50` still have callers only from `StartupWindow::RunUpdateCheck`.
- Decompilation still measures the incoming chunk with `strlen(Src)`, appends into the ANSI SSO buffer, and returns `elementSize * elementCount`.

## Ownership Decision

Keep this helper with [UID:0000O5][StartupWindow](by-file/StartupWindow.md). It is project glue between libcurl and the startup update/minimap version parser, not libcurl source and not a standalone generic string module based on current xrefs.

The surrounding parse helpers at `0x00581cf0`, `0x00581e40`, and `0x00581f50` are also currently startup-local. If future caller evidence shows broader use of the same ANSI SSO helper family, those helpers can move to a shared string utility, but `0x00581b80` should remain tied to the update-fetch path unless another callback setup site is found.

## Caveats

The callback measures the incoming chunk with `strlen(source)` instead of `elementSize * elementCount`. That is safe only for the observed text metadata downloads (`nexustk.ver` and `HashList.txt`) and should not be generalized as a binary-safe curl write sink.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001QM][client_s1-startup](by-meta/client_s1-startup.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and stale generated-source wording was removed.
  - Before: the libcurl write callback was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned startup updater glue under the validated StartupWindow file root; C++ remains blank because final callback typedef/signature and surrounding startup string helpers are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_581B80` at `0x00581b80`, size `0x166`, no direct callers, and string-buffer append callees; the page's xref evidence ties the function-pointer setup to `StartupWindow::RunUpdateCheck`.

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented the libcurl write callback behavior, repeated IDA checks, ownership decision, and text-only caveat but remained unevaluated.
  - After: score reflects detailed callback semantics, setup xrefs, startup-local ownership, and text-only caveat.
  - Evidence: IDA checks confirm callback-pointer setup inside `StartupWindow::RunUpdateCheck`, no direct callers, ANSI SSO append behavior, and `elementSize * elementCount` return.
