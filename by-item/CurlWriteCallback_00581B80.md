*** UID:0000UA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0001IP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CurlWriteCallback 0x00581B80

## Status

- Disposition: noncanonical alias/support page for [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md)
- Address range: `0x00581b80-0x00581ce6`
- Source module route: [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) emits through [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Autogen handling: non-emitting alias; keep formal C++ blank and do not duplicate the exact by-memory function body.
- Exact memory range: [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md)
- Parent memory range: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- Confidence: strong for alias identity, ownership, and behavior; the exact source body and formal C++ live on [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md).

## Behavior

This helper is the write callback passed to libcurl by `StartupWindow::RunUpdateCheck`. It appends each received text chunk into a MSVC/Dinkumware `std::string` response buffer used by the startup updater, preserving the same inline/heap storage convention as nearby string helpers.

This by-item page is retained only as a stable alias/support note for the old `CurlWriteCallback_00581B80` item. The canonical exact source body, owner/emitter route, and formal reconstructed C++ now live on [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md).

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

Rechecked on 2026-06-14:

- Live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, `sub_581B80` at `0x00581b80` with size `0x166` / 358 bytes, and the same two data refs at `0x00580c6f` and `0x00580efb` inside `sub_580870`.
- Disassembly still shows the callback computing the source length with a byte loop equivalent to `strlen`, reading the destination SSO length/capacity at offsets `+0x10`/`+0x14`, appending from `Src`, and retaining the cdecl callback shape with `Src`, element-size, element-count, and user-buffer arguments.

Rechecked on 2026-06-16:

- Live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed `sub_581B80` at `0x00581b80`, size `0x166`, with exactly two data xrefs from `StartupWindow::RunUpdateCheck` setup sites `0x00580c6f` and `0x00580efb`.
- `analyze_function` reports prototype `int __cdecl(const char *Src, int, int, void **)`, 20 basic blocks, cyclomatic complexity 6, no direct callers, and callees `_memmove_0`, `_memmove`, `sub_41B6E0`, `sub_5C7526`, `sub_41B6D0`, and `__invalid_parameter_noinfo_noreturn`.
- Adjacent helper xrefs remain StartupWindow-local: `0x00581cf0` has two `RunUpdateCheck` callers, `0x00581e40` has eight, and `0x00581f50` has two. This supports keeping the callback/string helper cluster in [UID:0000O5][StartupWindow](by-file/StartupWindow.md) rather than moving it to a shared string utility.
- Boundary bytes around `0x00581b70` reconfirm a prior return followed by `0xcc` padding through `0x00581b7f` and the callback prologue at `0x00581b80`.

## Ownership Decision

Keep the exact callback body with [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md), emitted through [UID:0000O5][StartupWindow](by-file/StartupWindow.md). This by-item is no longer a duplicate code emitter. The callback is project glue between libcurl and the startup update/minimap version parser, not libcurl source and not a standalone generic string module based on current xrefs.

The surrounding parse helpers at `0x00581cf0`, `0x00581e40`, and `0x00581f50` are also currently startup-local. If future caller evidence shows broader use of the same ANSI SSO helper family, those helpers can move to a shared string utility, but `0x00581b80` should remain tied to the update-fetch path unless another callback setup site is found.

## Caveats

The callback measures the incoming chunk with `strlen(source)` instead of `elementSize * elementCount`. That is safe only for the observed text metadata downloads (`nexustk.ver` and `HashList.txt`) and should not be generalized as a binary-safe curl write sink.

The former callback typedef/string-buffer source-quality blocker is resolved on [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) using current MCP evidence and a `std::string` user-data buffer. Final C++ remains blank here because this page is a noncanonical alias/support note; duplicate by-item function emission is intentionally rejected.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md)
- [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001QM][client_s1-startup](by-meta/client_s1-startup.md)

## Changes

- 2026-06-25 B003 accepted implementation callback:
  - What existed before: this by-item was reconstructable, emitted through [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and retained the same blank-C++ blocker as the exact by-memory page.
  - Changed to: noncanonical alias/support page with `CANONICAL_OWNER:0001IP`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++; the exact source body and generated output now live on [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md).
  - Summary/evidence: B003 live MCP session `80de0a67` resolved the callback as direct `StartupWindow.cpp` file-local libcurl glue over a `std::string` response buffer. Duplicate by-item emission, libcurl ownership, generic string utility ownership, broad aggregate source-body ownership, and binary-safe `append(contents, size * nmemb)` were rejected.
- 2026-06-16 A002 Goal 2 callback evidence refresh:
  - Raised completion/confidence from `85/88` to `86/89`.
  - Summary/evidence: live IDA reconfirmed the exact `0x00581b80-0x00581ce6` callback range, two `RunUpdateCheck` function-pointer setup refs, no direct callers, 20-block append/growth/free shape, SSO length/capacity offsets, adjacent helper caller locality, and clean padding before the callback. Owner/emitter remain [UID:0000O5][StartupWindow](by-file/StartupWindow.md); final C++ remains blank because the callback typedef and startup string-helper type names are not source-quality.
- 2026-06-14 A001 Goal 2 by-item score pass:
  - Raised completion from `84` to `85`; confidence remains `88`.
  - Summary/evidence: live IDA MCP reconfirmed the exact `0x00581b80-0x00581ce6` function, `0x166` / 358-byte size, two libcurl callback setup data refs in `StartupWindow::RunUpdateCheck`, SSO buffer length/capacity handling, text-only `strlen` caveat, and unchanged [UID:0000O5][StartupWindow](by-file/StartupWindow.md) owner/emitter route. Final C++ remains blank because the final callback typedef/signature and surrounding startup string helper split are not source-quality.
- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000O5][StartupWindow](by-file/StartupWindow.md), and stale generated-source wording was removed.
  - Before: the libcurl write callback was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned startup updater glue under the validated StartupWindow file root; C++ remains blank because final callback typedef/signature and surrounding startup string helpers are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_581B80` at `0x00581b80`, size `0x166`, no direct callers, and string-buffer append callees; the page's xref evidence ties the function-pointer setup to `StartupWindow::RunUpdateCheck`.

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented the libcurl write callback behavior, repeated IDA checks, ownership decision, and text-only caveat but remained unevaluated.
  - After: score reflects detailed callback semantics, setup xrefs, startup-local ownership, and text-only caveat.
  - Evidence: IDA checks confirm callback-pointer setup inside `StartupWindow::RunUpdateCheck`, no direct callers, ANSI SSO append behavior, and `elementSize * elementCount` return.
