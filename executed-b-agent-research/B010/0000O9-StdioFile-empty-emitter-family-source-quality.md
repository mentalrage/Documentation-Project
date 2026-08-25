** TARGET-REPORT-UID:0000O9 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000O9 StdioFile Empty-Emitter Family Source-Quality Report

## Targeted Revision Notice

This targeted revision supersedes the earlier phased recommendation. The current pass rechecked the previously unresolved empty markers with live MCP evidence and current support docs. Every empty marker now has an implementation-ready disposition: formal first-draft C++, formal no-code marker text, or an explicit source-placement/order plan. The remaining caveats are confidence caps and support-doc notes, not blockers for this report.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000O9] `by-file/StdioFile.md` as the active `NexusTK/util/StdioFile.cpp` generated root and approve one implementation callback that clears all 14 current empty StdioFile emitters.
- Final disposition: report-only research. No target/support by-* docs, generated files, coverage reports, validator state, queues, archives, supervisor ledgers, or IDA DB state were edited.
- Required action after supervisor acceptance: update the target by-file page, StdioFile class/aggregate/type support docs, and every StdioFile empty-emitter child page listed in the revised checklist; then run scoped validators with generated refresh.
- Confidence: high for the ownership/source route, concrete fields, vtable slot behavior, `Open`, `ReadRemaining`, and leaf virtuals; medium-high for the public string typedef spelling and `Tell`/`GetPosition` naming, which are now documentation caveats rather than no-code blockers.

## Target

- Target UID: `0000O9`
- Target path: `by-file/StdioFile.md`
- Generated file: `auto-generated/NexusTK/util/StdioFile.cpp`
- Assignment row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`: [UID:0000O9] has `15` total emitters, `1` filled, `14` marked empty, `6.7%` complete.
- Current by-file metadata: `COMPLETION:86`, `CONFIDENCE:88`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, `CANONICAL_OWNER:FILE`.
- Current generated header checked during revision: `validator-command-id: 000000003278`, `validator-refreshed-at: 2026-07-01T04:40:06-04:00`.

## Current Target State

`StdioFile.cpp` currently emits only [UID:0001IQ] `StdioFile::StdioFile()`:

```cpp
StdioFile::StdioFile()
{
    m_fileHandle = NULL;
    m_fileSize = 0;
}
```

The remaining generated empty markers are:

| UID | Page | Disposition |
| --- | --- | --- |
| `0000E6` | `by-class/StdioFile.md` | Source-facing class declaration/prototype block is now appropriate. Set class emitter position before method bodies and emit the first-draft declaration in this report, while preserving the `File` interface name caveats as support notes. |
| `0003H2` | `by-type/by-struct/StdioFileLayout.md` | Source-declaration support only; should receive a minimal no-standalone-code formal comment. |
| `0003I1` | `by-type/by-vtable/StdioFileVtable.md` | Compiler-generated vtable support; should receive a minimal no-manual-vtable formal comment. |
| `0001IR` | `by-memory/0x00582070-0x005824f6.StdioFile.md` | Aggregate/index over exact method children; should receive a minimal child-covered formal comment. |
| `00019F` | `by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md` | Safe code-ready leaf accessor. |
| `0001IS` | `by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md` | Safe code-ready source destructor body. |
| `0001IT` | `by-memory/0x005820d0-0x005821c9.StdioFileOpen.md` | Source-ready first-draft `void StdioFile::Open(const wchar_t *path)`: `_wstat64i32`-compatible stat buffer, `g_pfnWideStat`, `g_pfnWideOpenFile`, `FileError(path)` pointer throws, field stores, and ignored caller return evidence are all documented. |
| `0001IU` | `by-memory/0x005821d0-0x005821f7.StdioFileClose.md` | Safe code-ready virtual close method if the unchanged `m_fileHandle` behavior is preserved. |
| `0001IV` | `by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md` | Safe code-ready leaf cluster for `GetPosition`, `Seek`, and `Read`. |
| `0001IW` | `by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md` | Source-ready first-draft `int StdioFile::ReadLineChars(char *buffer, int limit)` preserving low-byte `0xff`, first-read EOF, CR extra-consume, LF, limit, zero-limit, and negative-limit behavior. |
| `0001IX` | `by-memory/0x005822d0-0x00582379.StdioFileReadLine.md` | Source-ready first-draft `bool StdioFile::ReadLine(StringBaseA &line)` using the accepted `mystr::StringBase<char,...>`/`StringBaseA` facade and preserving first-read-only EOF failure plus CR/LF handling. |
| `0002RH` | `by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md` | Source-ready first-draft non-virtual wide overload/helper `bool StdioFile::ReadLine(StringBaseW &line)` that calls virtual slot `+0x24`, converts/assigns unconditionally, cleans both temporaries, and returns the virtual status. |
| `0001IY` | `by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md` | Source-ready first-draft `int StdioFile::ReadRemaining(_AUTOBUF<unsigned char> &buffer)` preserving duplicate delete/free, remaining-count calculation, direct allocation, stores to `m_data/m_count`, and virtual `Read` return. |
| `0001J0` | `by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md` | Source-declared/generated-binary wrapper; should receive a no-standalone-source formal comment pointing to `0001IS`. |

## Evidence Checked

### Current MCP Evidence

MCP was available and used through the current `supervisor_resume_20260629` session. I used schema-current, narrow, exact-address calls only.

- `idb_list`: one active session, `supervisor_resume_20260629`, `NexusTK.exe.i64`, `is_analyzing:false`, worker pid `14860`.
- `server_health(database=supervisor_resume_20260629)`: `status:"ok"`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs` for the StdioFile family confirmed:
  - `0x004f5ad0` `sub_4F5AD0` size `0x4`.
  - `0x00582070` `sub_582070` size `0x2a`.
  - `0x005820a0` `sub_5820A0` size `0x27`.
  - `0x005820d0` `sub_5820D0` size `0xf9`.
  - `0x005821d0` `sub_5821D0` size `0x27`.
  - `0x00582200` `sub_582200` size `0x0c`.
  - `0x00582210` `sub_582210` size `0x1d`.
  - `0x00582230` `sub_582230` size `0x1a`.
  - `0x00582250` `sub_582250` size `0x71`.
  - `0x005822d0` `sub_5822D0` size `0xa9`.
  - `0x00582380` `sub_582380` size `0x85`.
  - `0x00582410` `sub_582410` size `0x49`.
  - `0x00582460` `sub_582460` size `0x35`.
  - `0x005824a0` `sub_5824A0` size `0x56`.
  - `0x005824f6` is not a function; `0x00582500` starts `sub_582500` size `0x52`.
- `int_convert` verified `0x0c` is decimal `12`, `0x04` is decimal `4`, `0x2a` is decimal `42`, `0x49` is decimal `73`, and `0x56` is decimal `86`.
- Targeted `decompile` confirmed the safe batch:
  - `0x004f5ad0`: `return this[2];`
  - `0x005820a0`: destructor reads `this[1]`, restores `StdioFile` vtable, closes when non-null, restores `File` vtable, and calls `sub_4F4A90`.
  - `0x005821d0`: close returns false for null handle, calls `fclose`, clears `this+0x08`, and returns `fclose(...) == 0`.
  - `0x00582200`: returns `ftell(this[1])`.
  - `0x00582210`: returns `fseek(this[1], offset, origin) == 0`.
  - `0x00582230`: returns `fread(buffer, 1, count, this[1])`.
  - `0x005824a0`: scalar deleting destructor repeats source destructor cleanup, then applies MSVC delete-flag wrapper behavior.
- Targeted `xrefs_to` confirmed:
  - `0x004f5ad0` has one data xref from `0x0062d5c8`.
  - `0x005821d0`, `0x00582200`, and `0x00582210` are vtable-only through `0x0062d5bc`, `0x0062d5c0`, and `0x0062d5c4`.
  - `0x00582230` has three direct `MapPaneLoadCompressedMapFile` code refs plus vtable slot `0x0062d5cc`.
  - `0x005824a0` has one vtable data xref from `0x0062d5ac`.
  - `0x0062d5ac` has exactly three vptr refs: constructor install `0x0058207f`, non-deleting destructor restore `0x005820a6`, and scalar-deleting destructor restore `0x005824a9`.
- Targeted `callees` confirmed:
  - `GetSize` has no callees.
  - Destructor/close/scalar wrapper call `_fclose` as expected.
  - Position/seek/read call `_ftell`, `_fseek`, and `_fread`.
  - Scalar wrapper also calls `sub_4F4A90`, `sub_4F4AC0`, and `_guard_check_icall_nop`.
- Revision MCP recheck on the same active session confirmed the previously unresolved bodies:
  - `idb_list`: active `supervisor_resume_20260629`, `is_analyzing:false`, worker pid `14860`; `server_health`: `status:"ok"`, Hex-Rays ready, strings cache ready.
  - `lookup_funcs` exact addresses: `0x005820d0` size `0xf9`, `0x00582250` size `0x71`, `0x005822d0` size `0xa9`, `0x00582380` size `0x85`, and `0x00582410` size `0x49`.
  - `xrefs_to` exact addresses: `Open` has four direct stack-object calls plus vtable slot `0x0062d5b8`; `ReadLineChars` and `ReadLine` are vtable-only at `0x0062d5d4` and `0x0062d5d0`; `ReadLineWideHelper` has no direct code/data xrefs; `ReadRemaining` has four direct calls from logo/startup/main-menu/map loaders.
  - `callees` exact addresses: `Open` calls `unk_69BE18`, `unk_69BE14`, `sub_4F4AA0`, `sub_4A6430`, `__CxxThrowException`, and stack-cookie support; `ReadLineChars` calls `_getc`; `ReadLine` calls `sub_582A80`, `_fgetc`, `sub_584200`, `sub_582BB0`, and `sub_582B30`; `ReadLineWideHelper` calls `sub_582A80`, `sub_582830`, `sub_582C60`, `sub_582B70`, and `sub_582B30`; `ReadRemaining` calls `j_j_j___free_base` and `unknown_libname_19`.
  - Bounded `disasm`/`decompile` confirms `Open` stores `_wfopen` result to `this+0x04`, copies the stat size field to `this+0x08`, throws a pointer-to-`FileError` object on stat/open failure, and all four direct callers ignore the return value, making `void Open(const wchar_t *path)` the best source declaration despite `EAX` retaining the `FILE*`.
  - Bounded `disasm`/`decompile` confirms `ReadLineChars` compares only `AL` with `0xff`, returns `-1` for first-read EOF and exact-limit fill, discards one byte after CR without checking LF, returns `-1` for limit `0`, and returns `0` for negative limits.
  - Bounded `disasm`/`decompile` confirms `ReadLine` assigns output only on CR/LF success, not on first-read EOF; later low-byte `0xff` follows the append path because only the first iteration has the EOF test.
  - Bounded `disasm`/`decompile` confirms `ReadLineWideHelper` is a non-virtual helper that calls vtable slot `+0x24`, converts/assigns to the wide destination even when the returned status is false, then destroys both temporaries.
  - Bounded `disasm`/`decompile` confirms `ReadRemaining` frees `dest+0x04` twice before replacement allocation, computes `remaining = m_fileSize - GetPosition()`, writes `dest+0x04`/`dest+0x08`, and returns the virtual `Read` result.
- Caller-return-use check for `Open`: decompiling `0x004f53b0`, `0x004f5710`, `0x004f6700`, and `0x00504b90` shows all four direct calls ignore `Open`'s return and immediately call `ReadRemaining` or `Read`; no direct caller branches on the returned `FILE*`.

### Documentation And Generated Inputs

- Target by-file: `by-file/StdioFile.md`.
- Generated output: `auto-generated/NexusTK/util/StdioFile.cpp`.
- Generated reports: `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-file-coverage.md`.
- Support docs: `by-class/StdioFile.md`, `by-class/File.md`, `by-file/File.md`, `by-file/FileIO.md`, `by-file/PathUtil.md`, `by-project-structure/proposed-source-tree.md`, `by-type/by-struct/StdioFileLayout.md`, `by-type/by-vtable/StdioFileVtable.md`, `by-type/by-vtable/FileStreamVtables.md`, and `by-type/by-struct/FileStreamLayouts.md`.
- Exact StdioFile child pages checked: `0001IQ`, `0001IR`, `00019F`, `0001IS`, `0001IT`, `0001IU`, `0001IV`, `0001IW`, `0001IX`, `0002RH`, `0001IY`, `0001J0`.
- Existing report searches used `rg` terms `0000O9`, `StdioFile`, `stdiofile`, `FileIO`, `PathUtil`, `00582070`, and `class_StdioFile`. Relevant lead opened: executed B006 constructor report `executed-b-agent-research/B006/0001IQ-StdioFileConstructor-empty-emitter-source-quality.md`. A-agent notes and `wave3_data_issues.md` were treated as leads only.
- No matching by-file report coverage row for [UID:0000O9] was found in `tools/leaser/Agents/b-report-coverage.md`.

## Positive Evidence Summary

- The by-file root is valid: [UID:0000O9] has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, generated output exists at `auto-generated/NexusTK/util/StdioFile.cpp`, and the FileIO/proposed-source-tree docs place `File.cpp`, `StdioFile.cpp`, and `PathUtil.cpp` together under `util/`.
- Ownership is stable: class-level StdioFile semantics live under [UID:0000E6], the source root is [UID:0000O9], and FileIO is an umbrella rather than the direct owner.
- The one filled constructor proves the route works: [UID:0001IQ] emits through [UID:0000E6] -> [UID:0000O9] into the current generated file.
- The safest next source bodies are small, exact, and already above the current C++ eligibility gate. Their final source does not require unresolved `FileError`, string helper, AUTOBUF, or platform dispatch source spellings.
- The structural markers for layout, vtable, aggregate, and scalar deleting destructor can be removed with formal no-standalone-code comments, preserving source semantics without hand-porting compiler-generated artifacts.

## Negative Evidence Summary

- Do not merge this file root into [UID:0000JD] `FileIO` during this batch. Current docs and generated output already use a working standalone `StdioFile.cpp`; FileIO remains the family umbrella.
- Do not move `PathExistsViaStat` into StdioFile. It is physically adjacent but has broad path-probe callers, no receiver/vtable/field use, and remains [UID:0000MI] `PathUtil`-owned.
- Do not keep `Open` blank. Current evidence resolves the source shape enough for first-draft C++: use `void StdioFile::Open(const wchar_t *path)`, `_stat64i32`-compatible stat storage, `g_pfnWideStat`, `g_pfnWideOpenFile`, `L"rb"`, `throw new FileError(path)`, and no source-level return value.
- Do not keep line-read bodies blank. Current evidence resolves the byte/EOF behavior and source-facing string type direction enough for first-draft C++: use `StringBaseA` / `StringBaseW` aliases for the accepted `mystr::StringBase<char/wchar_t,...>` facades and preserve the observed low-byte `0xff` behavior exactly.
- Do not keep `ReadRemaining` blank. Current evidence resolves the duplicate-free behavior and AUTOBUF source form enough for first-draft C++: use `_AUTOBUF<unsigned char> &`, `m_data`, `m_count`, and duplicate `delete [] buffer.m_data` statements before allocation to preserve binary behavior.
- Do not hand-author the scalar deleting destructor or vtable dwords. The compiler should regenerate these from a virtual destructor and class declaration; a formal comment is the correct marker-clearing action.
- Do not raise the file root to `95+`; exact original file granularity and full class/header declarations are still inferred.

## Heuristic / Inference Reanalysis And Validation

The older blocker "final C++ remains blank because below 95/95" is stale for code-entry. Current `by-structure.md` allows C++ when the item is reconstructable, has a nonblank emitter route to a file, and its average completion/confidence is greater than `85`. Most StdioFile children clear that minimum gate, but the minimum gate is not enough by itself; names, source placement, and dependencies still must be final-source quality for the specific body.

That distinction now separates the family into three implementation dispositions:

1. Previously safe leaf/source-declared set, still valid:
   - `00019F`, `0001IS`, `0001IU`, and `0001IV` can receive direct formal C++ because their bodies depend only on `m_fileHandle`, `m_fileSize`, and CRT `fclose`/`ftell`/`fseek`/`fread`.
   - `0001J0`, `0001IR`, `0003H2`, and `0003I1` can receive formal comments because they are source-declared/generated-binary or aggregate/support pages with no independent source body.
2. Additional source-ready bodies resolved by this revision:
   - `0001IT` `Open` is ready as a `void` method because all direct callers ignore the retained `FILE*` in `EAX`; the stack stat field at `this+0x08` maps to `_stat64i32`/`_wstat64i32` source shape; `FileError(const wchar_t *path)` and pointer-throw construction are already documented by `FileError` support pages.
   - `0001IW`, `0001IX`, and `0002RH` are ready with explicit `StringBaseA`/`StringBaseW` source aliases. Exact original typedef spelling remains inferred, but current project docs already accept `mystr::StringBase<char,...>` and `mystr::StringBase<wchar_t,...>` as the real pointer-backed string family. That uncertainty is a naming confidence cap, not a no-code reason.
   - `0001IY` is ready with `_AUTOBUF<unsigned char> &buffer`, `m_data`, and `m_count` because AUTOBUF support docs now confirm the concrete decorated type and fields. The duplicate free is not "fixed"; it is explicitly preserved as duplicate `delete [] buffer.m_data` statements in the formal first draft.
3. Class shell:
   - `0000E6` can receive a first-draft declaration/prototype block now. The implementation callback should set `EMITTER_POSITION_OPTIONAL:0` for the class shell so the generated declaration precedes already-emitted method bodies. The block should include the current method set, `FILE *m_fileHandle`, `int m_fileSize`, and the `StringBaseA`/`StringBaseW` aliases, while documenting that `Tell`/`GetPosition` and exact public typedef spellings remain inferred.

The source-facing field names `m_fileHandle` and `m_fileSize` are already accepted by the constructor callback and supported by layout/open/get-size evidence. They are inferred, not symbol-proven, but they are strong enough for the small methods in this batch. `NULL` remains the era-appropriate null spelling already used in the constructor; `nullptr` should not be introduced.

## Ranked Ownership Analysis

### 1. [UID:0000O9] `by-file/StdioFile.md`

- Evidence for: valid generated path, current generated file, class/aggregate children route to it, and source-tree docs list standalone `util/StdioFile.cpp`.
- Evidence against: exact original compact `FileIO.cpp` versus standalone `StdioFile.cpp` remains unproven.
- Decision: keep as active source root and generated destination. The compact `FileIO.cpp` possibility is not a blocker for this batch.

### 2. [UID:0000E6] `by-class/StdioFile.md`

- Evidence for: direct class owner for constructor, destructor, layout, vtable, and methods; field names and vtable semantics belong here.
- Evidence against: not the final by-file root; class declaration still depends on File interface naming.
- Decision: keep as direct class owner/emitter route for class-owned method pages; update as support doc.

### 3. [UID:0000JD] `by-file/FileIO.md`

- Evidence for: umbrella family groups File, StdioFile, and PathUtil.
- Evidence against: broader than the concrete StdioFile implementation; not the current generated root for these children.
- Decision: keep as context only. Do not reroute StdioFile emitters to FileIO in this pass.

### 4. [UID:0000JB] `by-file/File.md` and [UID:00004V] `by-class/File.md`

- Evidence for: abstract stream interface owns shared vtable contract.
- Evidence against: concrete field usage and method implementations are StdioFile-specific.
- Decision: dependency/support only; do not make StdioFile children File-owned.

### 5. [UID:0000MI] `by-file/PathUtil.md`

- Evidence for: adjacent `PathExistsViaStat` and shared file-existence helpers.
- Evidence against: the StdioFile methods use a receiver, vtable slots, and object fields; PathUtil helpers do not.
- Decision: reject for StdioFile method ownership; keep `PathExistsViaStat` excluded to PathUtil.

## Source Placement

Recommended placement remains `NexusTK/util/StdioFile.cpp`.

This placement fits the current source tree and behavior: `File.cpp` owns the abstract interface, `StdioFile.cpp` owns loose CRT file-stream implementation, and `PathUtil.cpp` owns stat/open path probes. `DATFile.cpp` remains under archive and `SoundManager` owns the Miles callback bridge that consumes file streams.

The exact historical one-file versus compact file-I/O split remains unresolved, but the current generated route is valid and already emits the constructor. This family should not remain mostly empty while waiting for original project-file proof that is not currently available.

## First-Draft C++ Recommendation

The by-file target itself has no formal `RECONSTRUCTION_CPP CODE` block because by-file pages are generated roots. The formal insertion text below is for the selected child/support emitters if the supervisor accepts this report.

### [UID:00019F] `StdioFileGetSize`

```cpp
int StdioFile::GetSize()
{
    return m_fileSize;
}
```

### [UID:0001IS] `StdioFileDestructor`

```cpp
StdioFile::~StdioFile()
{
    if (m_fileHandle != NULL) {
        fclose(m_fileHandle);
    }
}
```

### [UID:0001IU] `StdioFileClose`

```cpp
bool StdioFile::Close()
{
    if (m_fileHandle == NULL) {
        return false;
    }

    bool result = fclose(m_fileHandle) == 0;
    m_fileSize = 0;
    return result;
}
```

Do not add `m_fileHandle = NULL`; current MCP decompile shows only `m_fileSize` is cleared after `fclose`.

### [UID:0001IV] `StdioFileVirtualPositionReadMethods`

```cpp
int StdioFile::GetPosition()
{
    return ftell(m_fileHandle);
}

bool StdioFile::Seek(int offset, int origin)
{
    return fseek(m_fileHandle, offset, origin) == 0;
}

size_t StdioFile::Read(void *buffer, size_t count)
{
    return fread(buffer, 1, count, m_fileHandle);
}
```

`GetPosition` is the best current source-facing name for this batch because `by-class/StdioFile.md` and the aggregate already use it in method rows. The support docs should preserve that `Tell` remains an alias/interface naming caveat.

### [UID:0000E6] `StdioFile` Class Shell

Recommended implementation detail: set `EMITTER_POSITION_OPTIONAL:0` on `by-class/StdioFile.md` before inserting this class-shell block, so generated output places the declaration before method definitions.

```cpp
using StringBaseA = mystr::StringBase<char, mystr::mychar_traits<char>>;
using StringBaseW = mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>;

class StdioFile : public File
{
public:
    StdioFile();
    virtual ~StdioFile();

    virtual void Open(const wchar_t *path);
    virtual bool Close();
    virtual int GetPosition();
    virtual bool Seek(int offset, int origin);
    virtual int GetSize();
    virtual size_t Read(void *buffer, size_t count);
    virtual bool ReadLine(StringBaseA &line);
    virtual int ReadLineChars(char *buffer, int limit);

    bool ReadLine(StringBaseW &line);
    int ReadRemaining(_AUTOBUF<unsigned char> &buffer);

private:
    FILE *m_fileHandle;
    int m_fileSize;

    [[CHILDREN]]
};
```

`StringBaseA`/`StringBaseW` are report-local aliases for the accepted `mystr::StringBase<char/wchar_t, mystr::mychar_traits<...>>` family. If the implementation callback prefers project-wide aliases already present in surrounding docs, substitute those names but keep the same parameter roles and vtable slot order.

### [UID:0001IT] `StdioFileOpen`

```cpp
void StdioFile::Open(const wchar_t *path)
{
    struct _stat64i32 statBuffer;

    if (g_pfnWideStat(path, &statBuffer) == -1) {
        throw new FileError(path);
    }

    m_fileHandle = g_pfnWideOpenFile(path, L"rb");
    m_fileSize = statBuffer.st_size;

    if (m_fileHandle == NULL) {
        throw new FileError(path);
    }
}
```

`g_pfnWideStat` is the source-facing `0x0069be18` PlatformApi dispatch slot installed as `_wstat64i32`; `g_pfnWideOpenFile` is the `0x0069be14` `_wfopen` slot. Current direct callers ignore the return value, so the retained `FILE*` in `EAX` is compiler/register residue, not proof that the source method returns `FILE*`.

### [UID:0001IW] `StdioFileReadLineChars`

```cpp
int StdioFile::ReadLineChars(char *buffer, int limit)
{
    int bytesRead = 0;
    bool firstRead = true;

    if (limit > 0) {
        for (;;) {
            unsigned char ch = static_cast<unsigned char>(getc(m_fileHandle));

            if (firstRead && ch == 0xff) {
                return -1;
            }

            firstRead = false;

            if (ch == '\r') {
                getc(m_fileHandle);
                break;
            }

            if (ch == '\n' || ch == 0xff) {
                break;
            }

            buffer[bytesRead++] = static_cast<char>(ch);
            if (bytesRead >= limit) {
                break;
            }
        }
    }

    if (bytesRead == limit) {
        return -1;
    }

    return bytesRead;
}
```

This deliberately models the binary's low-byte `0xff` comparisons instead of an ordinary `EOF` `int` test. It also preserves zero-limit `-1`, negative-limit `0`, exact-fill `-1`, and the unconditional extra byte consumed after CR.

### [UID:0001IX] `StdioFileReadLine`

```cpp
bool StdioFile::ReadLine(StringBaseA &line)
{
    StringBaseA temp;
    bool firstRead = true;

    for (;;) {
        unsigned char ch = static_cast<unsigned char>(fgetc(m_fileHandle));

        if (firstRead && ch == 0xff) {
            return false;
        }

        firstRead = false;

        if (ch == '\r') {
            fgetc(m_fileHandle);
            break;
        }

        if (ch == '\n') {
            break;
        }

        char appended = static_cast<char>(ch);
        temp.Append(&appended, 1);
    }

    line = temp;
    return true;
}
```

Current MCP shows the first-read EOF path returns false without assigning the caller output. Later low-byte `0xff` values are appended, because the compiled loop only checks EOF while `firstRead` is true.

### [UID:0002RH] `StdioFileReadLineWideHelper`

```cpp
bool StdioFile::ReadLine(StringBaseW &line)
{
    StringBaseA temp;
    bool result = ReadLine(temp);

    line = StringBaseW(temp);
    return result;
}
```

This is a non-virtual convenience helper: no vtable slot points to `0x00582380`, and `xrefs_to` reports no direct references. The formal source still belongs to `StdioFile` because the helper lives inside the StdioFile island and calls the `File`/`StdioFile` line-read slot `+0x24`.

### [UID:0001IY] `StdioFileReadRemaining`

```cpp
int StdioFile::ReadRemaining(_AUTOBUF<unsigned char> &buffer)
{
    delete [] buffer.m_data;

    int remaining = m_fileSize - GetPosition();

    delete [] buffer.m_data;
    buffer.m_data = new unsigned char[remaining];
    buffer.m_count = remaining;

    return Read(buffer.m_data, remaining);
}
```

The duplicate delete is intentional. Current MCP and the exact page show two frees of `dest + 4` before any replacement store; existing direct callers pass fresh/null AUTOBUF destinations, but the reconstructed source must preserve the observed behavior rather than silently rewriting it as a single `Resize`.

### [UID:0001J0] `StdioFileScalarDeletingDestructor`

```cpp
// Compiler-generated scalar deleting destructor for StdioFile; source destructor code is emitted by [UID:0001IS].
```

### [UID:0001IR] `StdioFile` Aggregate

```cpp
// StdioFile aggregate emits through exact child method pages; this range has no separate source body.

[[CHILDREN]]
```

### [UID:0003H2] `StdioFileLayout`

```cpp
// StdioFile storage layout is declared by the StdioFile class; no standalone emitted code for this layout page.
```

### [UID:0003I1] `StdioFileVtable`

```cpp
// StdioFile vtable is compiler-generated from the StdioFile class declaration and virtual method definitions.
```

## Score And Metadata Recommendation

Recommended by-file target metadata after accepted incorporation:

```text
by-file/StdioFile.md
COMPLETION:88
CONFIDENCE:90
PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"
CANONICAL_OWNER:FILE
```

Rationale: the revised family report closes the by-file empty-emitter inventory, refreshes current MCP evidence, and gives every current empty marker an implementation-ready code/no-code disposition. Do not raise higher because final public typedef spelling, exact original `StdioFile.cpp` versus compact `FileIO.cpp` source granularity, and broader `File` base declaration coordination remain below final-audit certainty.

Recommended support score changes if the implementation callback is accepted:

| Page | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `by-class/StdioFile.md` | `88/86` | `90/89` | Class shell declaration/prototype block now implementation-ready with emitter position `0`, full method set, fields, and string aliases. |
| `by-memory/0x00582070-0x005824f6.StdioFile.md` | `86/89` | `89/91` | Aggregate empty state resolved for all child markers; exact children emit source or no-code comments. |
| `by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md` | `88/93` | `90/94` | Exact accessor C++ ready. |
| `by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md` | `86/90` | `89/92` | Normal destructor source body ready under current gate. |
| `by-memory/0x005821d0-0x005821f7.StdioFileClose.md` | `86/90` | `89/92` | Exact close source body ready, with untouched-handle caveat preserved. |
| `by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md` | `88/91` | `90/92` | Three leaf virtual method bodies ready. |
| `by-memory/0x005820d0-0x005821c9.StdioFileOpen.md` | `88/90` | `90/92` | `Open` source body ready with stat buffer, dispatch slots, `FileError` pointer throws, ignored return evidence, and field stores. |
| `by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md` | `88/91` | `90/92` | Raw char line-read source body ready with exact low-byte EOF/limit/CR behavior. |
| `by-memory/0x005822d0-0x00582379.StdioFileReadLine.md` | `88/90` | `90/91` | ANSI/string line-read source body ready with first-read EOF and CR/LF behavior preserved. |
| `by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md` | `86/90` | `88/91` | Non-virtual wide line helper source body ready; no-ref state preserved. |
| `by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md` | `88/91` | `90/92` | Read-remaining source body ready with duplicate-free and `_AUTOBUF<unsigned char>` fields preserved. |
| `by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md` | `88/92` | `90/93` | No-standalone-code proof is exact and source-declared/generated-binary. |
| `by-type/by-struct/StdioFileLayout.md` | `86/88` | `87/89` | Formal no-standalone-code disposition and current family audit. |
| `by-type/by-vtable/StdioFileVtable.md` | `87/92` | `88/93` | Formal no-manual-vtable disposition and current vptr evidence. |

No current StdioFile empty marker is left unresolved by this recommendation.

## Recommended Target Doc Changes

Target path: `by-file/StdioFile.md`

- Update scores to `88/90`.
- Add a 2026-07-01 B010 by-file family audit note with current generated state: `15` emitters, `1` filled, `14` empty before callback.
- Record that UID0001IQ constructor was already filled before this callback and that final generated `StdioFile.cpp` is refreshed at validator command `000000003353`.
- Record the recommended implementation batch: all 14 empty emitters, with source bodies for `0000E6`, `00019F`, `0001IS`, `0001IT`, `0001IU`, `0001IV`, `0001IW`, `0001IX`, `0002RH`, and `0001IY`, and formal no-code comments for `0001IR`, `0003H2`, `0003I1`, and `0001J0`.
- Preserve rejected alternatives: do not merge into FileIO now, do not move PathUtil, do not hand-port vtables/deleting destructors, do not collapse line-read low-byte behavior into ordinary `fgets`, do not replace the `ReadRemaining` duplicate-free behavior with `Resize`, and do not treat `Open` as caller-visible `FILE*` return.
- Preserve remaining caveats only as confidence caps: exact original compact file grouping, project-wide aliases for `StringBaseA`/`StringBaseW`, and broader `File` base declaration finalization.

## Recommended Support Doc Changes

- `by-class/StdioFile.md`: update score to `90/89`; set `EMITTER_POSITION_OPTIONAL:0`; add formal class declaration/prototype C++; record full method readiness and the remaining typedef/interface-name caveats as nonblocking.
- `by-memory/0x00582070-0x005824f6.StdioFile.md`: update score to `89/91`; replace stale "all sibling final source blank" wording with the exact all-marker disposition; add the aggregate formal comment above.
- `by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md`: add formal C++, raise to `90/94`, and update stale `95/95` gate language.
- `by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md`: add formal destructor C++, raise to `89/92`, and clarify compiler vtable/base teardown is implicit source output.
- `by-memory/0x005821d0-0x005821f7.StdioFileClose.md`: add formal close C++, raise to `89/92`, and preserve the "does not clear handle" caveat.
- `by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md`: add formal C++ for `GetPosition`, `Seek`, and `Read`, raise to `90/92`, and preserve `Tell` as an alias caveat.
- `by-memory/0x005820d0-0x005821c9.StdioFileOpen.md`: add formal `void StdioFile::Open(const wchar_t *path)` C++, raise to `90/92`, preserve `_stat64i32`/`_wstat64i32`, `g_pfnWideStat`, `g_pfnWideOpenFile`, `FileError` pointer-throw, and ignored-return proof.
- `by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md`: add formal C++, raise to `90/92`, and preserve low-byte `0xff`, first-read EOF, exact-fill `-1`, zero/negative limit, and CR extra-consume behavior.
- `by-memory/0x005822d0-0x00582379.StdioFileReadLine.md`: add formal C++, raise to `90/91`, and preserve first-read-only EOF failure, no output assignment on first EOF, CR extra-consume, and later `0xff` append behavior.
- `by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md`: add formal C++, raise to `88/91`, and preserve no-direct-xref state plus unconditional conversion/assignment after the virtual line-read call.
- `by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md`: add formal C++, raise to `90/92`, and preserve duplicate delete/free, `_AUTOBUF<unsigned char>` `m_data/m_count`, remaining-count calculation, and virtual `Read` return.
- `by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md`: add the formal no-standalone-code comment, raise to `90/93`, and preserve source-declared/generated-binary handling.
- `by-type/by-struct/StdioFileLayout.md`: add the formal no-standalone-code comment and B010 evidence note; optional score `87/89`.
- `by-type/by-vtable/StdioFileVtable.md`: add the formal no-manual-vtable comment and current `xrefs_to 0x0062d5ac` proof; optional score `88/93`.
- `by-file/FileIO.md`, `by-file/File.md`, `by-class/File.md`, `by-file/PathUtil.md`, `by-project-structure/proposed-source-tree.md`, `by-global/WideApiDispatchTable.md`, `by-class/FileError.md`, and `by-type/by-template/AUTOBUF_unsigned_char.md`: no edit required for the implementation callback unless the supervisor explicitly expands scope; they were evidence/support only and already contain the facts needed by this report.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| R01 | UID0000O9 remains the active generated root for `auto-generated/NexusTK/util/StdioFile.cpp`; current generated header is command `000000003278`, refreshed `2026-07-01T04:40:06-04:00`. | High | Target metadata, generated header, tracker row. | Applied to `by-file/StdioFile.md`; final generated header is command `000000003353`, refreshed `2026-07-01T05:14:25-04:00`. | incorporate | applied |
| R02 | Current generated state before callback remains `15` emitters, `1` filled, `14` empty. | High | `auto-generated/-ag-research-tracker.md`, generated `StdioFile.cpp`. | Applied to `by-file/StdioFile.md`; final generated file contains all accepted family UIDs and no StdioFile `Empty Emitter Marker` hits. | incorporate | applied |
| R03 | All 14 empty markers now have callback-ready dispositions; no additional report is required for the current StdioFile empty-emitter family. | High | Current MCP pass over the previously named blockers plus support docs. | Applied across target/support docs and verified by final generated `StdioFile.cpp` command `000000003353`. | incorporate | applied |
| R04 | UID0000E6 class shell should emit a first-draft declaration/prototype block and set `EMITTER_POSITION_OPTIONAL:0` so the declaration precedes method bodies. | Medium-high | StdioFile method set, vtable slots, layout fields, current generated order. | Applied to `by-class/StdioFile.md` with `EMITTER_POSITION_OPTIONAL:0`, class shell, and explicit `[[CHILDREN]]`. | incorporate | applied |
| R05 | `m_fileHandle +0x04` and `m_fileSize +0x08` remain accepted source-facing fields. | High | Constructor callback, Open/GetSize/ReadRemaining decompiles, layout docs. | Applied to `by-class/StdioFile.md`, `by-type/by-struct/StdioFileLayout.md`, and relevant child pages. | incorporate | applied |
| R06 | UID0001IT `Open` is source-ready as `void StdioFile::Open(const wchar_t *path)` with `_stat64i32`, `g_pfnWideStat`, `g_pfnWideOpenFile`, `L"rb"`, `m_fileHandle`, `m_fileSize`, and `throw new FileError(path)`. | High | Current MCP decompile/disasm/callees/xrefs; caller return-use check; WideApi and FileError docs. | Applied to `by-memory/0x005820d0-0x005821c9.StdioFileOpen.md`; generated output includes the body. | incorporate | applied |
| R07 | UID0001IW `ReadLineChars` is source-ready and must preserve low-byte `0xff`, first-read EOF, CR extra-consume, LF stop, exact-fill `-1`, zero-limit `-1`, and negative-limit `0`. | High | Current MCP decompile/disasm; exact page behavior. | Applied to `by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md`; generated output includes the body. | incorporate | applied |
| R08 | UID0001IX `ReadLine(StringBaseA &)` is source-ready and must preserve first-read-only EOF failure, no output assignment on first EOF, CR extra-consume, LF success, and later `0xff` append behavior. | High | Current MCP decompile/disasm/callees; StringBase docs. | Applied to `by-memory/0x005822d0-0x00582379.StdioFileReadLine.md`; generated output includes the body. | incorporate | applied |
| R09 | UID0002RH is a non-virtual StdioFile wide line helper with no direct xrefs; it should emit `bool StdioFile::ReadLine(StringBaseW &)` and keep unconditional conversion/assignment after the virtual read-line call. | Medium-high | Current MCP xrefs/decompile/disasm/callees; File vtable slot docs. | Applied to `by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md`; generated output includes the body. | incorporate | applied |
| R10 | UID0001IY `ReadRemaining` is source-ready with `_AUTOBUF<unsigned char> &`, `m_data`, `m_count`, duplicate delete/free, direct allocation, and virtual `Read` return. | High | Current MCP decompile/disasm/xrefs/callees; AUTOBUF docs. | Applied to `by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md`; generated output includes the body. | incorporate | applied |
| R11 | UID00019F, UID0001IS, UID0001IU, and UID0001IV safe source bodies from the original report remain valid. | High | Current and prior MCP decompiles/callees/xrefs. | Applied to their exact by-memory pages; generated output includes all four bodies. | incorporate | applied |
| R12 | UID0001IR, UID0003H2, UID0003I1, and UID0001J0 should use formal no-standalone-code/no-manual-vtable/source-declared comments, not raw vtable/deleting-destructor source. | High | by-structure compiler-generated/source-declared policy; current MCP vtable/deleting-destructor evidence. | Applied to aggregate/type/scalar-deleting pages; generated output includes all four comments. | incorporate | applied |
| R13 | FileIO remains umbrella evidence, not the direct StdioFile generated root; PathUtil remains owner for `PathExistsViaStat`. | High | Target/source-tree docs, xrefs and ownership docs. | Applied to `by-file/StdioFile.md` and aggregate/source-placement notes. | incorporate | applied |
| R14 | Recommended by-file score after accepted incorporation remains `88/90`; support score raises are listed for every changed child. | Medium-high | Complete empty-emitter disposition plus remaining source-granularity/type-alias confidence caps. | Applied to all accepted target/support metadata; final validators `000000003338`-`000000003353` returned `ok:1`. | incorporate | applied |

## Open Questions With Attempted Resolution

- Exact original file granularity: checked `StdioFile.md`, `FileIO.md`, `File.md`, `PathUtil.md`, and proposed source tree. Current evidence supports standalone `StdioFile.cpp`; compact `FileIO.cpp` remains possible but not strong enough to reroute or block.
- Class declaration C++: resolved for first draft. Current method set, vtable slots, layout fields, and file-root route support a class declaration block if `by-class/StdioFile.md` is emitted before child method bodies. `Tell`/`GetPosition` and exact `StringBaseA`/`StringBaseW` alias spellings remain confidence caps, not no-code blockers.
- `Open` source body: resolved for first draft. Current MCP shows `_wstat64i32`/`_wfopen` dispatch calls, stack stat size copied to `m_fileSize`, `FileError` pointer throws through `_TI4PAVFileError__`, and direct callers ignoring the return. Use `void Open(const wchar_t *path)`.
- Line-read methods: resolved for first draft. Current MCP shows raw byte/EOF/CR/LF/limit behavior, File vtable slots, string helper ownership as dependencies, and accepted `mystr::StringBase<char/wchar_t,...>` facades. Preserve low-byte `0xff` behavior.
- `ReadRemaining`: resolved for first draft. Current MCP shows duplicate-free, `_AUTOBUF<unsigned char>` layout support resolves `m_data/m_count`, and the formal source should preserve direct allocation instead of replacing it with `Resize`.

## Validator And Generated-Output Results

Implementation validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--wait-generated`. All final scoped commands exited `0`, reported `ok: 1`, and completed foreground generated refresh:

| File | command_id | command_timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-file/StdioFile.md` | `000000003338` | `2026-07-01T05:12:03-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-class/StdioFile.md` | `000000003339` | `2026-07-01T05:12:13-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x00582070-0x005824f6.StdioFile.md` | `000000003340` | `2026-07-01T05:12:23-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md` | `000000003341` | `2026-07-01T05:12:34-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md` | `000000003342` | `2026-07-01T05:12:44-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x005820d0-0x005821c9.StdioFileOpen.md` | `000000003343` | `2026-07-01T05:12:54-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x005821d0-0x005821f7.StdioFileClose.md` | `000000003344` | `2026-07-01T05:13:04-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md` | `000000003345` | `2026-07-01T05:13:14-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md` | `000000003346` | `2026-07-01T05:13:25-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x005822d0-0x00582379.StdioFileReadLine.md` | `000000003348` | `2026-07-01T05:13:35-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md` | `000000003349` | `2026-07-01T05:13:45-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md` | `000000003350` | `2026-07-01T05:13:55-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md` | `000000003351` | `2026-07-01T05:14:05-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-type/by-struct/StdioFileLayout.md` | `000000003352` | `2026-07-01T05:14:15-04:00` | 0 | 1 | completed, same command/timestamp |
| `by-type/by-vtable/StdioFileVtable.md` | `000000003353` | `2026-07-01T05:14:25-04:00` | 0 | 1 | completed, same command/timestamp |

Generated output check:

- `auto-generated/NexusTK/util/StdioFile.cpp` header is `validator-command-id: 000000003353`, `validator-refreshed-at: 2026-07-01T05:14:25-04:00`, equal to the final scoped validator command.
- `rg "Empty Emitter Marker" auto-generated/NexusTK/util/StdioFile.cpp` returned no matches.
- The generated file contains accepted family UIDs `0000E6`, `0003H2`, `0003I1`, `0001IR`, `00019F`, `0001IS`, `0001IT`, `0001IU`, `0001IV`, `0001IW`, `0001IX`, `0002RH`, `0001IY`, and `0001J0`.

## Changed Files

- `by-file/StdioFile.md`
- `by-class/StdioFile.md`
- `by-memory/0x00582070-0x005824f6.StdioFile.md`
- `by-type/by-struct/StdioFileLayout.md`
- `by-type/by-vtable/StdioFileVtable.md`
- `by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md`
- `by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md`
- `by-memory/0x005820d0-0x005821c9.StdioFileOpen.md`
- `by-memory/0x005821d0-0x005821f7.StdioFileClose.md`
- `by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md`
- `by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md`
- `by-memory/0x005822d0-0x00582379.StdioFileReadLine.md`
- `by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md`
- `by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md`
- `by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md`
- `tools/leaser/Agents/Agent-B010/research/0000O9-StdioFile-empty-emitter-family-source-quality.md`

Leases were acquired for the 15 by-* files, renewed during validation, and released with `python leaser.py B010 unlease`; all 15 release lines returned `Success`.

## Implementation Tracking Checklist

- [x] Report metadata header added: `TARGET-REPORT-UID:0000O9` and `AUTHOR-AGENT-ID:B010`.
- [x] Update `by-file/StdioFile.md` to `COMPLETION:88`, `CONFIDENCE:90`; preserve `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"` and `CANONICAL_OWNER:FILE`; record generated header `000000003278` / `2026-07-01T04:40:06-04:00` and pre-callback state `15` emitters, `1` filled, `14` empty. Applied in status/file-role/method-evidence/changes.
- [x] Update `by-class/StdioFile.md` to `COMPLETION:90`, `CONFIDENCE:89`; set `EMITTER_POSITION_OPTIONAL:0`; insert the formal class shell/prototype block; preserve `m_fileHandle +0x04`, `m_fileSize +0x08`, vtable slot order, `StringBaseA`/`StringBaseW` alias caveat, and `Tell`/`GetPosition` caveat. Applied with explicit `[[CHILDREN]]`.
- [x] Update `by-memory/0x00582070-0x005824f6.StdioFile.md` to `89/91`; insert formal aggregate comment plus `[[CHILDREN]]`; replace stale unresolved-marker wording with all-marker disposition.
- [x] Update `by-type/by-struct/StdioFileLayout.md` to `87/89`; inserted formal no-standalone-code comment and preserved field layout.
- [x] Update `by-type/by-vtable/StdioFileVtable.md` to `88/93`; inserted formal no-manual-vtable comment and preserved `0x0062d5ac` xref/slot evidence.
- [x] Update `by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md` to `90/94`; inserted formal `int StdioFile::GetSize()` body.
- [x] Update `by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md` to `89/92`; inserted formal destructor body and preserved compiler vtable/base teardown explanation.
- [x] Update `by-memory/0x005820d0-0x005821c9.StdioFileOpen.md` to `90/92`; inserted formal `void StdioFile::Open(const wchar_t *path)` body; preserved `_stat64i32`/`_wstat64i32`, `g_pfnWideStat`, `g_pfnWideOpenFile`, `throw new FileError(path)`, field stores, and ignored return proof.
- [x] Update `by-memory/0x005821d0-0x005821f7.StdioFileClose.md` to `89/92`; inserted formal close body and preserved no-`m_fileHandle = NULL` caveat.
- [x] Update `by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md` to `90/92`; inserted formal `GetPosition`, `Seek`, and `Read` bodies; preserved `Tell` alias caveat.
- [x] Update `by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md` to `90/92`; inserted formal body; preserved low-byte `0xff`, first-read EOF, CR extra-consume, LF, exact-fill, zero-limit, and negative-limit behavior.
- [x] Update `by-memory/0x005822d0-0x00582379.StdioFileReadLine.md` to `90/91`; inserted formal body; preserved first-read-only EOF failure, no output assignment on first EOF, CR/LF behavior, and later `0xff` append behavior.
- [x] Update `by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md` to `88/91`; inserted formal non-virtual wide helper body; preserved no-direct-xref state and unconditional conversion/assignment.
- [x] Update `by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md` to `90/92`; inserted formal body; preserved duplicate delete/free, `_AUTOBUF<unsigned char>` `m_data/m_count`, direct allocation, remaining-count calculation, and virtual `Read` return.
- [x] Update `by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md` to `90/93`; inserted formal no-standalone-code comment.
- [x] Evidence-only support docs were not edited: `by-file/FileIO.md`, `by-file/File.md`, `by-class/File.md`, `by-file/PathUtil.md`, `by-project-structure/proposed-source-tree.md`, `by-global/WideApiDispatchTable.md`, `by-class/FileError.md`, and `by-type/by-template/AUTOBUF_unsigned_char.md`.
- [x] Scoped validators with `--wait-generated` completed for every listed target/support file; command IDs `000000003338`-`000000003353`, all exit `0`, all `ok:1`.
- [x] Generated `auto-generated/NexusTK/util/StdioFile.cpp` refreshed to final validator header `000000003353` / `2026-07-01T05:14:25-04:00` and has no remaining StdioFile `Empty Emitter Marker` hits from the 14-marker family.
- [x] Claim And Incorporation Ledger verification states updated to `applied` for every accepted claim.
- [x] No generated files, coverage reports, validator state, queues, archives, supervisor ledgers, by-project-structure docs, or IDA DB files were manually edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000O9-StdioFile-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000O9-StdioFile-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T05:21:20","uid":"0000O9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
