** TARGET-REPORT-UID:00015U **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015U BuildFieldMapPath Source-Quality Research

Assignment id: `B002-goal2-build-field-map-path-source-quality-00015U-20260618`

Primary target: [UID:00015U] `by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md`

Report-only status: no by-memory, by-class, by-file, by-global, generated report, generated source, IDA DB, or shared coverage-report edits were made. All replacement text below is for supervisor application.

## Final Recommendation

Keep [UID:00015U] as a reconstructable file-local helper emitted through [UID:0000JA] `FieldMapPane`.

Recommended target metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 91
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000JA
EMITTER_UIDS: 0000JA
```

Recommended source-facing declaration:

```cpp
static void BuildFieldMapPath(const wchar_t *sourcePath, wchar_t *fieldMapPath);
```

The function is best kept under the existing `BuildFieldMapPath` source-facing name for this target because its only caller is the `FieldMapPane` constructor and the caller immediately appends `.EPF`, uppercases the resulting buffer, and uses it as the field-map EPF resource path. `CopyPathStem` is the exact behavior alias and should be recorded in the body text, but making it the primary source name would overstate broader utility ownership that the xref evidence does not support.

Formal first-draft C++ should be populated now. The target is reconstructable, has a valid emitter chain to `NexusTK/map/FieldMapPane.cpp`, clears the active combined-score code gate after this source-quality pass, and has no range/split/owner blocker. Remaining uncertainty is only original spelling, not behavior or source placement.

## Evidence Checked

Read and compared:

- [UID:00015U] `by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md`
- [UID:00014Z] `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`
- [UID:00004U] `by-class/FieldMapPane.md`
- [UID:0000JA] `by-file/FieldMapPane.md`
- [UID:00025B] `by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md`
- [UID:0003P9] `by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md`
- [UID:0000TQ] `by-global/WideApiDispatchTable.md`
- [UID:0000MI] `by-file/PathUtil.md`
- [UID:00022K] `by-memory/0x004b81f0-0x004b821e.FileExists.md`
- [UID:00022J] `by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md`
- [UID:000150] `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md`
- [UID:000151] `by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md`
- B003 executed report `tools/leaser/Agents/Agent-B003/research/executed/00014Z-field-map-pane-source-quality.md`
- B001/B003 executed reports around `WideStringHashHelper`, `FileExists`, and the shared `.EPF` suffix
- `by-memory/-coverage-report.md`
- `by-class/-coverage-report.md`
- `by-file/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/map/FieldMapPane.cpp`
- `simroot_v2/class_FieldMapPane.cpp`
- `by-project-structure/proposed-source-tree.md`
- `by-structure.md`
- `inference_research.md`

Binary evidence was checked against the read-only PE image:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

IDA MCP was not used to mutate the IDA DB. Current report conclusions are based on current docs plus read-only local PE parsing/disassembly. This is sufficient for this target because the range is a simple exact function with a direct caller and imported dispatch-slot context that can be verified from the PE.

## Raw Binary Facts

PE section facts from the read-only executable:

- Image base: `0x00400000`.
- `.text` section begins at VA `0x00401000`.
- The target lies in executable `.text`.

Exact boundary:

- `0x004b821e-0x004b8220` is `cc cc` padding.
- `0x004b8220` starts `push ebp; mov ebp, esp`.
- `0x004b8279` is the primary `ret`.
- `0x004b8282` jumps back to the common copy path after a dot is found.
- `0x004b8284-0x004b8290` is twelve bytes of `cc` padding.
- No split or merge is supported. The predecessor [UID:00022K] `FileExists` ends at `0x004b821e`; the successor padding starts exactly at `0x004b8284`.

Instruction-level body:

```asm
004b8220  push ebp
004b8221  mov  ebp, esp
004b8223  mov  edx, [ebp+8]        ; sourcePath
004b8226  mov  ecx, edx
004b8228  push esi
004b8229  push edi
004b822a  lea  esi, [ecx+2]
004b8230  mov  ax, [ecx]           ; inline wcslen-style scan
004b8233  add  ecx, 2
004b8236  test ax, ax
004b8239  jne  0x004b8230
004b823b  sub  ecx, esi
004b8240  sar  ecx, 1              ; source length in wide chars
004b8242  lea  eax, [edx-2+ecx*2]  ; last source character
004b8245  cmp  edx, eax
004b8247  ja   0x004b825d          ; empty string
004b8250  cmp  word ptr [eax], 0x2e
004b8254  je   0x004b827a          ; last dot found
004b8256  sub  eax, 2
004b8259  cmp  edx, eax
004b825b  jbe  0x004b8250
004b825d  mov  eax, ecx            ; no dot: copy full source
004b825f  mov  esi, [ebp+0xc]      ; destination
004b8262  lea  edi, [eax+eax]      ; byte count
004b8265  push edi
004b8266  push edx
004b8267  push esi
004b8268  call 0x005c95b0          ; _memmove
004b826d  add  esp, 0xc
004b8270  xor  eax, eax
004b8272  mov  [edi+esi], ax       ; destination[copyChars] = L'\0'
004b8276  pop  edi
004b8277  pop  esi
004b8278  pop  ebp
004b8279  ret
004b827a  cmp  edx, eax
004b827c  ja   0x004b825d
004b827e  sub  eax, edx
004b8280  sar  eax, 1              ; chars before dot
004b8282  jmp  0x004b825f
```

Calling convention and return:

- The function is caller-cleanup `cdecl`.
- The call at `0x004b0c0d` pushes two stack arguments and the later `add esp, 0x14` at `0x004b0c24` cleans both helper arguments plus the three `_wcscat_s` arguments.
- The binary leaves `EAX == 0` because `xor eax,eax` is used to write the wide NUL terminator. The caller ignores the value. This is not strong proof of a source-level `int` return. A `static void` helper is more source-like and matches the side-effect-only contract.

Caller/route scan:

- PE-aware rel32 call/jump scan found exactly one external branch into `0x004b8220-0x004b8284`: `call 0x004b8220` at `0x004b0c0d`.
- No external short branch enters the function body.
- No little-endian VA pointer to the target start or interior was found in the PE scan.
- A single RVA-pattern interior hit for `0x004b8232` is a raw byte coincidence, not a meaningful table route; it is not a VA xref and does not point to the function start.

Callee set:

- `_memmove` at `0x005c95b0`.
- No global reads, imports, file APIs, allocation/free helpers, or resource loaders occur inside [UID:00015U].

## Constructor Context

The only caller is the `FieldMapPane` constructor-family body at [UID:00014Z] `0x004b0bb0-0x004b129b`.

Relevant constructor instructions:

```asm
004b0bd6  mov  esi, ecx
004b0bdd  call 0x00544460          ; Pane::Pane(&this->Pane, 0)
004b0be2  lea  edi, [esi+0xf8]     ; destination = this + 0xf8
004b0bef  push edi
004b0bf0  push [ebp+8]             ; sourcePath constructor arg
004b0bf3  mov  [esi], 0x0061a3c8
004b0bf9  mov  [esi+0xa0], 0x0061a414
004b0c03  mov  [esi+0xa4], 0x0061a444
004b0c0d  call 0x004b8220          ; BuildFieldMapPath(sourcePath, this+0xf8)
004b0c12  push 0x0061a44c          ; pooled L".EPF"
004b0c17  push 0x80
004b0c1c  push edi
004b0c1d  call 0x005de0f0          ; _wcscat_s(this+0xf8, 0x80, L".EPF")
004b0c24  add  esp, 0x14
004b0c27  ...                      ; inline wcslen(this+0xf8)
004b0c3f  push eax                 ; character count
004b0c40  push edi                 ; buffer
004b0c41  call dword ptr [0x0069be58]
```

The import/initializer evidence resolves `0x0069be58` as the `CharUpperBuffW` wide API dispatch slot:

- The wide API initializer writes `0x0069be58` from IAT cell `0x0060d39c`.
- PE import parsing resolves `0x0060d39c` to `USER32.dll!CharUpperBuffW`.
- Therefore the constructor uppercases the finished `fieldMapEpfPath` in place after appending `.EPF`.

This corrects the current vague "wide API dispatch path helper" wording. The constructor sequence is:

1. Copy source path stem into `this+0xf8`.
2. Append pooled use-site suffix `L".EPF"` with `_wcscat_s(..., 0x80, L".EPF")`.
3. Compute the current wide length.
4. Call `CharUpperBuffW(fieldMapEpfPath, length)` through [UID:0000TQ] `WideApiDispatchTable`.
5. Continue entry-table initialization and later render/load paths use the completed EPF resource path.

Field declaration:

```cpp
wchar_t m_fieldMapEpfPath[0x80]; // FieldMapPane +0x0f8, 128 wide chars
```

Evidence for this declaration:

- Constructor computes `edi = this + 0xf8`.
- The helper writes a wide string at that destination.
- `_wcscat_s` uses `0x80` as the destination capacity.
- The next known FieldMapPane data block begins at `this+0x1f8`, leaving exactly `0x100` bytes between `+0xf8` and `+0x1f8`, or 128 UTF-16 code units.
- B003's executed aggregate report already modeled the same field as `fieldMapEpfPath[0x80]`.

Buffer contract:

- [UID:00015U] has no local destination-size parameter and performs no local capacity check.
- The constructor's `_wcscat_s(..., 0x80, L".EPF")` protects only the append operation after the helper has already copied the stem.
- The source contract therefore must be caller/data-side: the source path stem must fit in `m_fieldMapEpfPath` before and after suffix append.
- For the whole constructor sequence to be valid, `stemLength + 4 + 1 <= 0x80`, so the source path stem must be at most `0x7b` / 123 wide characters before `.EPF` is appended.
- Adding a local `destSize` parameter or local truncation in [UID:00015U] would be an unsafe source rewrite because it would change the binary contract and call signature.

## Behavior For Incorporation

[UID:00015U] copies a wide source-path stem to a caller-provided wide destination buffer. It first scans forward to the source NUL terminator, then scans backward from the last source character to find the last `L'.'` anywhere in the string. If a dot is found, it copies the characters before that dot. If no dot is found, it copies the entire source string. It does not treat path separators specially, so it is not a basename/path normalizer. For an empty input string or an input whose first character is `L'.'`, it copies zero bytes and writes only the destination NUL. The copy uses `_memmove(destination, sourcePath, copyChars * sizeof(wchar_t))`, allowing overlap at the ABI level even though the known caller passes separate buffers. It then writes `destination[copyChars] = L'\0'`.

The helper does not append `.EPF`, uppercase, allocate, free, open a file, dispatch through the platform API table, load resources, touch FieldMapPane fields directly, or validate capacity. Those are caller-side constructor responsibilities.

## Heuristic / Inference Reanalysis And Validation

### Helper Name

Best recommendation: keep `BuildFieldMapPath` as the source-facing helper name for this page and formal C++, while documenting `CopyPathStem` as the exact behavior alias.

Evidence:

- The only caller is the `FieldMapPane` constructor at `0x004b0c0d`.
- The caller passes the constructor source path and `this+0xf8`, appends `L".EPF"`, uppercases the buffer via `CharUpperBuffW`, and uses the resulting path as the FieldMap EPF resource path.
- Existing target/support docs and generated routing already attach this helper to [UID:0000JA] `FieldMapPane`.
- No other module calls the helper, no pointer-table route is known, and no PathUtil page lists this as a shared path utility.

Rejected alternatives:

- Primary name `CopyPathStem`: behavior-accurate but too generic for the direct source owner. It risks implying [UID:0000MI] `PathUtil` ownership, while the evidence only proves FieldMapPane use. Keep this wording in behavior text, not as the emitted name.
- Anonymous file-local helper with no stable name: weaker because the project already has a stable page name and the call context supports a descriptive source name. Lack of original symbols does not require leaving a generated or anonymous name in draft source.
- Generated `sub_4B8220`: rejected because behavior, caller, and source placement are now sufficiently resolved.

Impact:

- No final C++ blocker remains. Use `static void BuildFieldMapPath(...)` in the formal block and mention that exact original spelling is inferred/descriptive.

### Signature And Return Value

Best source signature:

```cpp
static void BuildFieldMapPath(const wchar_t *sourcePath, wchar_t *fieldMapPath);
```

Evidence:

- The binary is `cdecl` with two stack arguments.
- `[ebp+8]` is read only as the source wide string.
- `[ebp+0xc]` is written as the destination wide buffer.
- The only caller ignores `EAX`.
- The final `EAX == 0` comes from zeroing `AX` for the terminator store; it is not enough to prove a meaningful source-level status return.

Rejected alternatives:

- `int __cdecl BuildFieldMapPath(...)`: ABI-compatible with the incidental final `EAX` value, but less source-like because no caller uses a status and there is no error path.
- `wchar_t *BuildFieldMapPath(...)`: no return of the destination pointer is visible; the helper leaves zero in `EAX`.
- Class method `FieldMapPane::BuildFieldMapPath(...)`: rejected because the function has no `this` receiver and receives the destination explicitly.

Impact:

- Change the current doc's "always-zero return" wording to "leaves `EAX` zero incidentally; no source-level return contract is proven."

### Destination Field Name And Declaration

Best declaration:

```cpp
wchar_t m_fieldMapEpfPath[0x80]; // +0x0f8
```

Evidence:

- Constructor passes `this + 0xf8` as the helper destination.
- `_wcscat_s(this + 0xf8, 0x80, L".EPF")` immediately follows.
- `0x1f8` is the first entry-record table base, so the path buffer occupies exactly `0x100` bytes / 128 UTF-16 code units.
- Rendering and EPF-load context in generated/simroot output use the same path buffer as the map EPF path.

Rejected alternatives:

- Raw `word_`/byte array: weaker because the constructor capacity, wide-string calls, and resource suffix prove a wide path string.
- `m_sourcePath` or `m_pathStem`: incomplete because the stored value after constructor completion includes `.EPF` and is uppercased.
- Heap/string object type: rejected because no constructor/destructor/allocation/string-object method is called for the field; it is an inline fixed wide buffer.

Impact:

- FieldMapPane class support should promote `fieldMapEpfPath[0x80]` from review-only draft shape into the class layout notes.

### Buffer Capacity Contract

Best inference: fixed caller-side contract with no local size guard.

Evidence:

- [UID:00015U] takes no `size_t`/capacity argument and directly `_memmove`s `copyChars * 2` bytes.
- The known caller provides a fixed 128-wide-character destination and appends a four-character suffix with `_wcscat_s`.
- The caller-side secure append is too late to prevent a stem-copy overflow if the source stem exceeds the inline buffer.

Rejected alternatives:

- Add a `destSize` parameter to the reconstructed helper: rejected because it changes the ABI and no caller pushes it.
- Rewrite with `_wcsncpy_s` or checked truncation: rejected because it changes overflow/invalid-parameter behavior and would no longer match the compiled function.
- Treat `_wcscat_s` as proving the helper itself is safe: rejected because the helper has already copied before `_wcscat_s` runs.

Impact:

- Formal C++ should preserve the no-size helper and document the precondition in comments or body notes.
- The score should not exceed low-90s confidence because the original source relied on an external input-size contract we cannot prove from a resource definition.

### Source Placement

Best placement: file-local helper in [UID:0000JA] `NexusTK/map/FieldMapPane.cpp`.

Evidence:

- One direct caller, inside the FieldMapPane constructor.
- The destination field and path use are FieldMapPane-specific.
- The proposed source tree already includes `map/FieldMapPane.cpp`.
- [UID:00004U] and [UID:0000JA] clear the current owner/emitter gate.
- [UID:0003P9] proves the `.EPF` suffix use-site includes FieldMapPane, but the suffix is a pooled literal and not a standalone FieldMap helper owner.

Rejected alternatives:

- [UID:0000MI] `PathUtil`: the helper body is path-like, and the predecessor [UID:00022K] `FileExists` is PathUtil-owned, but adjacency is weak. Unlike `FileExists` and `PathExistsViaStat`, [UID:00015U] has only one caller and no filesystem API, no stat/open behavior, and no cross-subsystem utility surface.
- [UID:0000ML] `PlatformApi`: rejected because PlatformApi owns `CharUpperBuffW` dispatch storage at `0x0069be58`, not this caller-local stem-copy helper.
- [UID:0000L3] `MapPane` or [UID:0000PB] `WorldMapPane`: rejected because they share the pooled `.EPF` suffix, not this helper's code.
- Larger field-dialog module: possible as an original source-file granularity alternative, but no constructor caller or source metadata proves it. Current best route remains `map/FieldMapPane.cpp`.

Impact:

- Keep `CANONICAL_OWNER:0000JA` and `EMITTER_UIDS:0000JA`.
- No split/merge/rename is required.

### `.EPF` Suffix And Read-Only Data Relationship

Best inference:

- [UID:00015U] does not own or reference the `.EPF` literal.
- The constructor source-use at `0x004b0c12` references [UID:0003P9] pooled `L".EPF"`.
- [UID:0003P9] correctly remains `CANONICAL_OWNER:NONE` with emitters `0000JA,0000L3,0000PB`.

Evidence:

- [UID:00015U] has no string/global xref.
- PE scan resolves exactly four VA immediates to `0x0061a44c`, including FieldMapPane, MapPane, and WorldMapPane contexts.
- The current shared-literal page already rejects a FieldMap-only owner.

Rejected alternatives:

- Assign `.EPF` suffix ownership to FieldMapPane adjacency: rejected by direct non-FieldMap xrefs.
- Treat `.EPF` suffix as a global constant consumed by [UID:00015U]: rejected because the helper does not reference it.

Impact:

- Target docs should refer to `.EPF` only as caller-side constructor context.
- Formal C++ for [UID:00015U] should not include the suffix append; that belongs to the constructor page or future constructor child.

### Wide API Dispatch Slot `0x0069be58`

Best inference: `g_pfnCharUpperBuffW` / `CharUpperBuffW` dispatch slot in [UID:0000TQ] `WideApiDispatchTable`.

Evidence:

- The constructor calls through `[0x0069be58]` with `(fieldMapEpfPath, wcslen(fieldMapEpfPath))`.
- The wide API initializer writes `0x0069be58` from IAT cell `0x0060d39c`.
- PE import parsing resolves `0x0060d39c` to `USER32.dll!CharUpperBuffW`.
- This matches in-place uppercasing of a resource path after `.EPF` append.

Rejected alternatives:

- Unknown "wide API dispatch path helper": stale/vague now that the import is resolved.
- Filesystem/path resolver: no output buffer, current-directory, or `GetFullPathNameW` style signature is present; the call has exactly `LPWSTR, DWORD`.
- FieldMap-owned helper: rejected because the callee is a PlatformApi dispatch table entry.

Impact:

- Add a support row/note to [UID:0000TQ] for `0x0069be58`.
- Update target/support docs to say the constructor uppercases the path through PlatformApi, rather than "finishes" it through an unnamed path helper.

### Generated Output Pollution

Current generated state:

- `auto-generated/NexusTK/map/FieldMapPane.cpp` is empty because formal C++ blocks are blank.
- `auto-generated/-ag-memory-coverage.md` lists [UID:00015U] as emitting through `0000JA` but `coded` is `no`.
- `simroot_v2/class_FieldMapPane.cpp` contains a useful lead showing `BuildFieldMapPath(sourcePath, mapPath); _wcscat_s(mapPath, 0x80, L".EPF"); g_pfnFinalizeWidePath(...)`, but it uses modern types, generated casts, wrong owner aliases in other methods, and a wrong/vague name for the `[0x0069be58]` dispatch call.

Rejected generated artifacts:

- `std::uint16_t *` source path types for this helper; source should use `const wchar_t *`.
- Modern `auto`, `reinterpret_cast`, and generated `FittingRoomDownloadControlPane` owner aliases.
- `g_pfnFinalizeWidePath` for `[0x0069be58]`; the import evidence says `CharUpperBuffW`.

Impact:

- Formal C++ should be hand-written source-like C++, not copied from simroot.
- After supervisor application and autogen, [UID:00015U] should move from `coded no` to coded output inside `auto-generated/NexusTK/map/FieldMapPane.cpp`.

### Split / Merge Decision

No split or merge is recommended.

Evidence:

- One exact prologue/epilogue body from `0x004b8220` through `0x004b8284`.
- Clean padding before and after.
- One coherent helper role.
- One external caller.

Rejected alternatives:

- Merge with [UID:00022K] `FileExists`: rejected by padding, different owner, different behavior, and separate caller set.
- Merge with [UID:00022J] `WideStringHashHelper`: rejected by padding and no shared caller/behavior.
- Merge with [UID:000150] or [UID:00014Z]: rejected because [UID:00015U] is outside the FieldMapPane aggregate range and has its own exact function boundary.
- Split dot-scan/copy subranges: no nested function boundaries exist.

Impact:

- Keep one by-memory page and raise score.

### Remaining Uncertainty

Remaining uncertainty is limited and non-blocking:

- Exact original spelling of `BuildFieldMapPath` is inferred. The behavior alias `CopyPathStem` remains useful in prose.
- The original source may have placed `FieldMapPane` inside a larger field-map dialog module, but current docs and source tree route it to `map/FieldMapPane.cpp`.
- The constructor allocation site remains unresolved at [UID:00014Z], but the helper's direct caller and emitter route are proven.
- The original input-source constraints that guarantee the stem length are not visible in this function. The capacity precondition is inferred from caller-side buffer size and suffix append.

These uncertainties cap confidence below final-audit range but do not block `88/91` or formal first-draft C++.

## First-Draft C++ Recommendation

Populate the target's formal C++ block with:

```cpp
static void BuildFieldMapPath(const wchar_t *sourcePath, wchar_t *fieldMapPath)
{
    const wchar_t *end = sourcePath;
    while (*end != L'\0') {
        ++end;
    }

    const wchar_t *lastDot = 0;
    const wchar_t *scan = end;
    while (scan != sourcePath) {
        --scan;
        if (*scan == L'.') {
            lastDot = scan;
            break;
        }
    }

    const size_t copyChars = (lastDot != 0)
        ? static_cast<size_t>(lastDot - sourcePath)
        : static_cast<size_t>(end - sourcePath);

    memmove(fieldMapPath, sourcePath, copyChars * sizeof(wchar_t));
    fieldMapPath[copyChars] = L'\0';
}
```

Notes for supervisor application:

- This is source-like C++ for the helper's own range only. Do not include `_wcscat_s`, `CharUpperBuffW`, or FieldMapPane constructor code in [UID:00015U]'s formal block.
- The source uses `void` because the only observed caller ignores the incidental zero in `EAX`; the zero is needed for the terminator store.
- The helper intentionally has no capacity parameter. Do not add one in formal C++ for this range.
- If the project later chooses `CopyPathStem` as a shared utility name, the body can be renamed without changing behavior. Current evidence favors the FieldMap-local `BuildFieldMapPath` name.

Constructor context for [UID:00014Z] / [UID:00004U] support docs only:

```cpp
BuildFieldMapPath(sourcePath, m_fieldMapEpfPath);
_wcscat_s(m_fieldMapEpfPath, 0x80, L".EPF");
g_pfnCharUpperBuffW(m_fieldMapEpfPath, wcslen(m_fieldMapEpfPath));
```

## Exact Supervisor Edits

### Target [UID:00015U] Metadata

Placement: replace the existing metadata values in `by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md`.

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Target [UID:00015U] Status Replacement

Placement: replace the current `## Status` bullet list.

```markdown
## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: file-local/static helper function.
- Address range: `0x004b8220-0x004b8284`, end-exclusive.
- Current IDA label: `sub_4B8220`; source-facing recommendation `BuildFieldMapPath`, with behavior alias `CopyPathStem`.
- Likely source module: [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md), emitted through `NexusTK/map/FieldMapPane.cpp`.
- Rebuild handling: `source-authored`.
- Signature shape: `static void BuildFieldMapPath(const wchar_t *sourcePath, wchar_t *fieldMapPath)`. The binary is caller-cleanup `cdecl` with two stack arguments. It leaves `EAX` zero as a side effect of writing the wide NUL terminator, but no caller observes a return value and no source-level status return is proven.
- Confidence: very strong for exact boundary, padding, single caller, callee set, argument roles, FieldMapPane destination field, caller-side `.EPF` append, and `CharUpperBuffW` uppercase dispatch; high but not final-audit for exact original helper spelling and source input-size precondition.
- Reconstruction note: first-draft formal C++ is ready. Use the helper body only; keep suffix append and uppercase call in constructor-level docs.
```

### Target [UID:00015U] Behavior Replacement

Placement: replace the current `## Behavior` section.

```markdown
## Behavior

`BuildFieldMapPath` is a FieldMapPane-local path-stem copy helper. It scans the source wide string to its NUL terminator, scans backward for the last wide `'.'`, copies the source characters before that dot when one exists, copies the whole source string when no dot exists, and writes a wide NUL terminator in the destination. Empty input and input beginning with `'.'` produce an empty destination string. The helper does not check path separators, so it is not a complete path normalizer or basename extractor. It does not append `.EPF`, uppercase, allocate, open files, load resources, touch globals, or validate the destination capacity.

The known caller is the `FieldMapPane` constructor. It passes the constructor source path and `this+0xf8`, then appends the pooled use-site suffix `L".EPF"` with `_wcscat_s(this+0xf8, 0x80, L".EPF")`, computes the buffer length, and calls the wide API dispatch slot `0x0069be58`, now resolved as `CharUpperBuffW`, to uppercase the completed EPF path in place.

The destination field should be declared as `wchar_t m_fieldMapEpfPath[0x80]` at `FieldMapPane+0x0f8`. The helper itself has no size parameter, so the source contract is external: for the whole constructor sequence to be valid, the copied stem must be at most `0x7b` wide characters before appending the four-character `.EPF` suffix and the NUL terminator into a `0x80`-wide-character buffer.
```

### Target [UID:00015U] IDA / Binary Evidence Insert

Placement: add under the target evidence section, replacing stale "wide API dispatch path helper" wording where present.

```markdown
- B002 2026-06-18 read-only PE reanalysis confirms the exact `0x004b8220-0x004b8284` body, two `0xcc` bytes before it, twelve `0xcc` bytes after it, one external rel32 call at `0x004b0c0d`, no external short branch into the body, no meaningful pointer-table route, and `_memmove` as the only callee.
- The constructor context is `lea edi,[esi+0xf8]`, `push edi`, `push [ebp+8]`, `call 0x004b8220`, `push 0x0061a44c`, `push 0x80`, `push edi`, `_wcscat_s`, inline `wcslen`, and `call dword ptr [0x0069be58]`.
- PE import/initializer parsing resolves `0x0069be58` as the PlatformApi `CharUpperBuffW` dispatch slot: the initializer writes it from IAT cell `0x0060d39c`, which imports `USER32.dll!CharUpperBuffW`.
- The apparent zero return is incidental. The instruction `xor eax,eax; mov [edi+esi],ax` writes the wide terminator and leaves `EAX` zero, but the sole caller ignores it.
```

### Target [UID:00015U] Open Questions Replacement

Placement: replace the current `## Open Questions` section.

```markdown
## Open Questions / Resolved Source-Quality Notes

- Resolved: source placement remains [UID:0000JA] `FieldMapPane`, not [UID:0000MI] `PathUtil`, because the helper has exactly one caller and that caller uses a FieldMapPane inline path buffer.
- Resolved: destination field declaration is `wchar_t m_fieldMapEpfPath[0x80]` at `FieldMapPane+0x0f8`.
- Resolved: the caller-side dispatch after suffix append is `CharUpperBuffW`, not an unknown path-finalization helper.
- Resolved: formal C++ should be populated under the active code-entry gate.
- Remaining non-blocking uncertainty: exact original helper spelling is not symbol-proven. Keep `BuildFieldMapPath` as the source-facing FieldMap-local name and record `CopyPathStem` as the behavior alias.
```

### Target [UID:00015U] Score Rationale Replacement

Placement: replace the target `## Score Rationale` bullets.

```markdown
## Score Rationale

- Completion `88`: the page now records the exact body and padding, cdecl two-argument shape, source/destination roles, `_memmove` dependency, single constructor caller, no hidden branch/pointer route, source-stem copy behavior including empty and leading-dot cases, `m_fieldMapEpfPath[0x80]` destination declaration, caller-side `.EPF` append and `CharUpperBuffW` uppercase sequence, capacity precondition, source placement, rejected PathUtil/shared utility alternatives, and first-draft C++.
- Confidence `91`: confidence is very strong because raw PE disassembly, caller context, import parsing, current FieldMapPane support docs, executed B003 aggregate research, and coverage state all agree. It remains below final-audit range because exact original helper spelling and the upstream source-path length guarantee are inferred rather than symbol- or resource-definition-proven.
```

### Target [UID:00015U] Formal C++ Block

Placement: populate `RECONSTRUCTION_CPP CODE` with the block from `## First-Draft C++ Recommendation`.

### [UID:00004U] FieldMapPane Class Support Update

Placement: add under class layout notes or live evidence.

```markdown
- B002 2026-06-18 [UID:00015U] reanalysis resolves the constructor path buffer at `+0x0f8` as `wchar_t m_fieldMapEpfPath[0x80]`. The constructor passes this field to the file-local `BuildFieldMapPath` helper, appends pooled use-site `L".EPF"` with `_wcscat_s(...,0x80,...)`, computes the resulting length, and uppercases the completed EPF path through the PlatformApi `CharUpperBuffW` dispatch slot `0x0069be58`. The first entry table remains at `+0x1f8`, confirming the path field occupies exactly `0x100` bytes.
```

No class score change is required. The class still has broader aggregate/raw-helper C++ blockers, but the coverage-row wording should no longer say final field/helper names are generally unresolved without naming the resolved path field.

### [UID:0000JA] FieldMapPane File Support Update

Placement: add under proposed contents or method summary for `BuildFieldMapPath`.

```markdown
- [UID:00015U] is now source-ready as a file-local `BuildFieldMapPath` helper in `NexusTK/map/FieldMapPane.cpp`. It copies the constructor source path stem into `FieldMapPane::m_fieldMapEpfPath[0x80]`, leaving `.EPF` append and `CharUpperBuffW` uppercasing to the constructor. This rejects moving the helper to `PathUtil.cpp`: the body is path-like, but the only proven caller and only proven destination are FieldMapPane-specific.
```

No file score change is required.

### [UID:00025B] / [UID:0003P9] Read-Only Data Support Update

Placement: add a note to [UID:00025B] parent or [UID:0003P9] child if the supervisor wants the FieldMap constructor path sequence cross-linked.

```markdown
- [UID:00015U] does not own or reference the `.EPF` literal directly. The FieldMapPane constructor references [UID:0003P9] at `0x004b0c12` after `BuildFieldMapPath` returns, then appends the pooled use-site suffix to `m_fieldMapEpfPath[0x80]`. Keep [UID:0003P9] no-canonical-owner with emitters `0000JA,0000L3,0000PB`; the literal should appear as use-site `L".EPF"` text in constructor/source contexts, not as a global owned by [UID:00015U].
```

### [UID:0000TQ] WideApiDispatchTable Support Update

Placement: add a row near the other `0x0069be5*` / UI/window dispatch entries.

```markdown
| `0x0069be58` | `g_pfnCharUpperBuffW` / `dword_69BE58` | `CharUpperBuffW` | [UID:00014Z] `FieldMapPane` constructor uppercases `m_fieldMapEpfPath` after appending `.EPF`; PE import parsing resolves initializer source IAT cell `0x0060d39c` to `USER32.dll!CharUpperBuffW`. |
```

Add evidence note:

```markdown
- B002 2026-06-18 [UID:00015U] source-quality reanalysis resolves the FieldMapPane constructor's `call dword ptr [0x0069be58]` as `CharUpperBuffW(fieldMapEpfPath, wcslen(fieldMapEpfPath))`, not a FieldMap-owned path helper. The slot is installed from IAT cell `0x0060d39c`, which imports `USER32.dll!CharUpperBuffW`.
```

## Coverage Row Recommendation

Agents must not edit shared coverage reports directly. The following rows are exact supervisor-owned replacement text.

### `by-memory/-coverage-report.md` [UID:00015U]

Replace the current [UID:00015U] row with:

```markdown
    - [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md) 0x004b8220-0x004b8284 | file-static helper | BuildFieldMapPath : reconstructable : 88% : very strong : B002 2026-06-18 source-quality reanalysis confirms exact `0x64` body, two-byte leading padding and twelve-byte trailing padding, caller-cleanup two-argument cdecl shape, source wide-string and destination wide-buffer roles, `_memmove`-only callee, single rel32 caller at `0x004b0c0d` in the FieldMapPane constructor, no external short branch or pointer-table route, path-stem copy behavior with last-dot stripping and wide NUL termination, incidental zero `EAX` but no source-level return contract, `FieldMapPane+0x0f8` destination declaration as `wchar_t m_fieldMapEpfPath[0x80]`, caller-side `_wcscat_s(...,0x80,L".EPF")`, caller-side `CharUpperBuffW` dispatch through `0x0069be58`, external stem-length precondition, rejection of PathUtil/shared utility/generated `sub_4B8220` naming, owner/emitter [UID:0000JA], and first-draft C++ readiness.
```

### `by-class/-coverage-report.md` [UID:00004U]

Replace the current [UID:00004U] row with this score-preserving update:

```markdown
- [UID:00004U][FieldMapPane](by-class/FieldMapPane.md) : reconstructable : 86% : strong : Field map/list UI attached to FieldMapPane.cpp; A002/B003 live IDA rechecks reconfirm modeled method/helper sizes, vtable-backed render/mouse/key slots, three request-helper callers, constructor-only path-helper caller, raw rectangle-helper no-function/no-ref status, component graph, unique class-span signature, and B002 2026-06-18 resolution of `m_fieldMapEpfPath[0x80]` at `+0x0f8`, the file-local `BuildFieldMapPath` helper, pooled `.EPF` append, and `CharUpperBuffW` uppercase dispatch. Class formal C++ remains blank pending aggregate/child emission policy and raw rectangle-helper liveness, not because the path buffer/helper remains unresolved.
```

### `by-file/-coverage-report.md` [UID:0000JA]

Replace the current [UID:0000JA] row with this score-preserving update:

```markdown
- [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md) : reconstructable : 88% : strong : `NexusTK/map/FieldMapPane.cpp` with refreshed IDA method sizes, vtable stores/slots, FieldMap-only request/path helper callers, opcode `0x3f`/7-byte request behavior, verified numeric conversions, raw rect-helper no-function/no-ref caveat, padding boundaries, map/dialog split caveat, and B002 2026-06-18 source-quality closure for [UID:00015U] as a file-local `BuildFieldMapPath` helper over `m_fieldMapEpfPath[0x80]` with caller-side `.EPF` append and `CharUpperBuffW` uppercase dispatch.
```

No coverage row change is required for [UID:0003P9] unless the supervisor wants the FieldMap constructor sequence cross-link added. Its current no-owner/multiple-emitter row remains correct.

## Validator Commands

Suggested commands after supervisor application:

> Executable block R001 was removed from this report and preserved verbatim in [00015U-BuildFieldMapPath-source-quality-removed.md](00015U-BuildFieldMapPath-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated-output effect after formal C++ is populated: [UID:00015U] should emit into `auto-generated/NexusTK/map/FieldMapPane.cpp`, and `auto-generated/-ag-memory-coverage.md` should change the row from emitted but `coded no` to coded output for this helper.

## Changed Files / Direct-Edit Statement

Created exactly one report file:

```text
tools/leaser/Agents/Agent-B002/research/00015U-BuildFieldMapPath-source-quality.md
```

No by-memory, by-class, by-file, by-global, generated report, generated source, IDA database, project-level report, or shared coverage-report files were edited by this agent. All metadata, support-doc, C++ block, and coverage changes above are recommendations for supervisor-owned application.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00015U-BuildFieldMapPath-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00015U"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015U-BuildFieldMapPath-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00015U-BuildFieldMapPath-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
