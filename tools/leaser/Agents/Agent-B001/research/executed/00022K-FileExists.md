## Final Report / Current Recommendation

Target: [UID:00022K] `by-memory/0x004b81f0-0x004b821e.FileExists.md`

Current recommendation: assign `FileExists` to [UID:0000MI] `PathUtil`.

Final target state:
- `COMPLETION:88`
- `CONFIDENCE:90`
- `RECONSTRUCTABLE:TRUE`
- `AUTOGEN_PARENT_UID:0000MI`
- `AUTOGEN_PARENT_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE:` blank

Recommended status/classification: source-authored, reconstructable, single free helper function. No child split is needed: live IDA MCP confirms one exact function at `0x004b81f0-0x004b821e`, padding before/after, and next function start at `0x004b8220`.

Concrete next action for supervisor: accept B001-022 as resolved/assigned to `PathUtil`. No A-agent follow-up is required for this target beyond ordinary future final-C++/source-name work.

Report state: final.

Confidence: high for behavior, range, and direct semantic ownership by `PathUtil`; medium-high for exact original source file granularity because the original project may have folded path helpers into a compact `FileIO.cpp`. That caveat does not block the current by-structure parent assignment because `PathUtil` is the narrowest documented owner and now clears the strict gate.

## Changed Files

Manually edited documentation:
- `source-3/project-documentation/by-memory/0x004b81f0-0x004b821e.FileExists.md`
- `source-3/project-documentation/by-file/PathUtil.md`
- `source-3/project-documentation/by-memory/0x00582460-0x00582495.PathExistsViaStat.md`
- `source-3/project-documentation/by-item/PathExistsViaStat_00582460.md`
- `source-3/project-documentation/by-file/FileIO.md`
- `source-3/project-documentation/by-memory/-coverage-report.md`
- `source-3/project-documentation/by-file/-coverage-report.md`
- `source-3/project-documentation/by-item/-coverage-report.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00022K-FileExists.md`

Validator-managed side effects: targeted validator scans refreshed autogen/project state as needed. The first target scan updated the autogen parent registry for `00022K` from blank to `0000MI`; later filtered scans reported autogen reports unchanged.

## Validator Results

Command form used for each by-* file:

```text
python source-3/project-documentation/tools/validator.py --mode file --file <path> --apply
```

Results:
- `by-memory/0x004b81f0-0x004b821e.FileExists.md`: `ok: 1`, last used UID `00032N`
- `by-file/PathUtil.md`: `ok: 1`, last used UID `00032N`
- `by-memory/0x00582460-0x00582495.PathExistsViaStat.md`: `ok: 1`, last used UID `00032N`
- `by-item/PathExistsViaStat_00582460.md`: `ok: 1`, last used UID `00032N`
- `by-file/FileIO.md`: `ok: 1`, last used UID `00032N`
- `by-memory/-coverage-report.md`: `ok: 1`, last used UID `00032N`
- `by-file/-coverage-report.md`: `ok: 1`, last used UID `00032N`
- `by-item/-coverage-report.md`: `ok: 1`, last used UID `00032N`

The research report itself is outside the by-* validator scope.

## Supporting Research

### IDA Evidence For `FileExists`

Live IDA MCP checks on 2026-06-10:
- `idb_meta`: `NexusTK.exe`, base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- `lookup_funcs`: `sub_4B81F0` at `0x004b81f0`, size `0x2e`; no function at `0x004b821e`; next function `sub_4B8220` at `0x004b8220`, size `0x64`.
- `decompile 0x004b81f0`: calls `dword_69BE14(path, L"rb")`, returns `0` on null, calls `fclose` on success, returns `1`.
- `disasm 0x004b81f0`: `push offset aRb_0`, `push [ebp+arg_0]`, `call dword_69BE14`, null test, `_fclose`, boolean return.
- `callers` / `xrefs_to 0x004b81f0`: exactly three code refs: `0x0049c87c`, `0x0049c88f`, and `0x004dbcb5`.
- `callees`: exactly `_fclose` and `dword_69BE14`.
- IDA Python byte/xref pass: `0x004b81f0-0x004b821e` is the exact function; `0x004b821e-0x004b8220` is padding; the local neighborhood has function starts at `0x004b81f0`, `0x004b8220`, and `0x004b8290`.

Caller context:
- `0x0049c87c` and `0x0049c88f` are inside `_DATFileMgr::LoadDATFileIndex`, testing the incoming archive path and a `"../"` fallback before loading/indexing a DAT container.
- `0x004dbcb5` is inside `MonsterImageLib::LoadMonsterArchives`, testing numbered `DATA/MON%d.DAT` paths and ending the archive scan at the first missing DAT.

Dispatch-table evidence:
- `xrefs_to 0x0069be14` shows initializer write at `0x0041a42e` in `sub_41A280` and many consumers, including `FileExists` at `0x004b81fe` and `StdioFile::Open` at `0x00582118`.
- The broad consumer set confirms `dword_69BE14` is the PlatformApi/WideApi dispatch slot, not source ownership evidence for the helper body.

### PathUtil Ownership Evidence

The closest semantic sibling is [UID:0001IZ] `0x00582460-0x00582495.PathExistsViaStat`, now refreshed to `86/88`:
- IDA reports `sub_582460` at `0x00582460-0x00582495`.
- Decompilation is a pure boolean existence probe: `dword_69BE18(path, stackStatBuffer) != -1`.
- Callers are cross-subsystem: `0x004f5765`, `0x004f5781`, `0x004f640d`, `0x004f6853`, `0x00504c7d`, and `0x0057b6be`.
- Callees are only `dword_69BE18` and the stack-cookie check.

`FileExists` and `PathExistsViaStat` differ only in the backend probe:
- `FileExists`: `_wfopen(path, L"rb")`, close on success.
- `PathExistsViaStat`: `_wstat64i32(path, stackStatBuffer)`.

Both are free path probes with no class receiver, no archive state, no monster state, no stream object fields, and no dispatch-table storage. This makes `PathUtil` the narrowest direct semantic parent. `FileIO` remains the umbrella layer.

### Rejected Alternatives

`FileIO` [UID:0000JD]:
- Evidence for: broad file utility umbrella; includes `File`, `StdioFile`, and `PathUtil`.
- Evidence against direct parent: it is intentionally broader than the actual direct owner. `PathUtil` exists, now clears `87/88`, and owns the sibling path-existence probe. By-structure prefers the narrowest defensible direct parent.

`StdioFile` / `File`:
- Evidence for: uses the same `_wfopen` dispatch slot and lives in the file I/O subsystem.
- Evidence against direct parent: `StdioFile::Open` is an object-stateful virtual method. It stats the path, opens the file, stores `FILE*` and size fields, and throws `FileError`. `FileExists` has no `this`, no field writes, no vtable relationship, and no exception path. `File` is the abstract stream interface, not a free filesystem-probe owner.

`PlatformApi` / `WideApiDispatchTable`:
- Evidence for: owns the `_wfopen` function pointer consumed at `0x004b81fe`.
- Evidence against direct parent: IDA shows many consumers of `0x0069be14`. PlatformApi owns the dispatch storage and initializer; consumers keep their own source ownership.

`DATFileMgr`:
- Evidence for: two direct callers in `_DATFileMgr::LoadDATFileIndex`.
- Evidence against direct parent: the helper body has no DAT manager object access, no `g_pDATFileMgr`, no archive-table state, and one non-DAT caller. The DAT manager is a consumer.

`MonsterImageLib`:
- Evidence for: one direct caller in `MonsterImageLib::LoadMonsterArchives`.
- Evidence against direct parent: the helper body has no monster table/cache/singleton state and is also used by DAT manager code. MonsterImageLib is a consumer.

New utility owner:
- Rejected. The proposed `PathUtil` source root already exists under `NexusTK/util/`, already owns `PathExistsViaStat`, and now has a coherent two-helper scope. Creating a new one-item owner would add a narrower-but-artificial source root without stronger binary evidence.

### Final Caveats

- Final C++ remains blank under the project final-code gate. The body is simple, but final source spelling for the helper and platform dispatch accessor is not at `95/95`.
- Original source-file granularity is inferred. The original tree may have used a compact `FileIO.cpp` instead of a standalone `PathUtil.cpp`; current documentation still benefits from the `PathUtil` direct owner because it models the real semantic submodule and clears the parent gate.
- Historical generated names remain leads only. The assignment is based on IDA MCP range/body/xref evidence plus current by-structure ownership rules.

