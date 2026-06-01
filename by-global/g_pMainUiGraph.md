*** UID:0000RF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMainUiGraph

## Status

- Confidence: strong for address and main-UI-root role; medium for exact concrete type and full layout.
- Address: `0x0067aba4`
- IDA name: `dword_67ABA4`
- Proposed name: `g_pMainUiGraph`
- Main source owner: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- Memory storage page: [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md)

## Summary

`dword_67ABA4` is the global main UI graph/root object pointer used by pre-login dialogs, login-success handoff, post-login UI bootstrap, and teardown/attachment checks. The strongest current evidence is the login-success caller: `LoginDialogPane::OnServerMessage` loads `dword_67ABA4` into `ecx` immediately before calling [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) at `0x004f7d10`.

Generated `simroot_v2` metadata and reconstructed snippets refer to the callee parameter as `MainUiGraph* uiGraph` and show a provisional `loginNameCache[128]` field used by the user-status and login-name notification paths. Treat `g_pMainUiGraph` as the current working source name, but keep the full class/struct layout provisional until live IDA/source-map review recovers more fields.

## Evidence

- [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md) records the exact storage range as a reconstructable source-authored global pointer. It also records a prior 2026-05-28 IDA MCP result of 31 direct xrefs to `dword_67ABA4`.
- `0x004fac95` reads the global immediately before the direct call at `0x004fac9b` to `InitializeMainUiGraph`.
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) records the exact callee range, the single executable caller, and the `mov ecx, dword_67ABA4` handoff into the initializer.
- `simroot_v2/recovered/InitializeMainUiGraph_004F7D10.cpp` models the callee as `InitializeMainUiGraph(MainUiGraph* uiGraph)`, uses `uiGraph->loginNameCache` in both new and old layout user-status paths, calls profile/input/ready helpers in the common tail, and adds `uiGraph` to the pane/child registry.
- Generated dialog code still contains direct attachment references such as `sub_49E190(this, 0, dword_67ABA4)`, supporting this global as the dialog-to-root attachment target. This is generated-data evidence only and must stay below IDA confidence.
- Wave2 notes for `0x004f7d10` describe the initializer as rooted on `g_pMainUiGraph`.
- Live IDA MCP was unavailable during the 2026-05-30 review pass, so no new xref count was claimed here.

## Known Role Boundaries

- Owns or points at the persistent post-login UI graph/root object.
- Carries at least the login-name cache consumed by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md).
- Is adjacent to browser/web-board dialog singleton storage in memory, but [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md) keeps it separate from that cluster.
- Should be sourced with [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), not with individual login dialog, account dialog, or browser dialog files.

## Open Questions

- Confirm the exact concrete type name for the object behind `dword_67ABA4`.
- Separate graph/root ownership from nearby globals such as `dword_67A7CC` and `dword_69B36C`, which also appear in UI root/screen setup paths.
- Recover the field layout beyond the provisional `loginNameCache[128]` evidence consumed by `InitializeMainUiGraph` and user/status panes.
- Re-run live IDA xrefs when MCP is available to refresh the prior 31-xref count and classify write, clear, attach, and read-only uses.

## Cross-References

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md)

## Changes

- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and a short summary that did not link the exact storage page.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:80`, an explicit storage-page link, expanded evidence, role boundaries, and live-IDA availability caveat.
  - Summary/evidence: exact by-memory storage page [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainUiGraph](by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md), existing MainUiGraph/InitializeMainUiGraph docs, prior IDA-recorded xref count, and `simroot_v2/recovered/InitializeMainUiGraph_004F7D10.cpp` support the address and root-object role. Score is capped because concrete type name, full field layout, and current live xref classification remain unresolved.
