# Report Revalidation Issue Pass

Date: 2026-07-02

Scope: reports currently marked `REPORT-VALIDATION-STATUS: needs-revalidation`
under `executed-b-agent-research/`.

Evidence used:

- Dry validator rescan from `source-3/project-documentation`:
  `python .\tools\validator_background.py --mode execute-rescan-reports --lock-timeout 60 --no-generated-refresh`
- Current `auto-generated/-ag-research-tracker.md` errors.
- Current report headers and report body target/source references.
- Current by-memory/by-class/by-file docs and `tools/validator.ini`.

No by-* docs, executed reports, validator registry files, or generated reports
were changed during this pass.

## Executive Findings

- The validator reports 209 revalidation report files.
- Those collapse to 92 distinct source/target groups.
- Every group has current project documentation containing useful source/target
  information. I did not find a group where the original source evidence is
  simply gone.
- The biggest issue is not source invalidity. It is registry/index drift:
  80 groups have a current by-memory doc with the same UID, but that UID is not
  present in `tools/validator.ini` `[files]`, so the report is treated as
  `target_uid_unknown`.
- This is part of a larger index issue: a quick scan found 881 current
  `by-memory/*.md` files with UID headers that are not present in
  `tools/validator.ini` `[files]`.
- 12 report files have no `TARGET-REPORT-UID` header. Most of those are broad
  or multi-target reports. Their target docs are current and registered, but the
  reports cannot count as single-target executed coverage until retargeted or
  split into target-specific executions.
- I found no broad evidence that these reports should be invalidated due to
  source drift. Most should be handled as registry repair, retargeting, or
  re-execution decisions.

## Recommended Handling

1. Do not bulk invalidate these reports.
2. Fix the validator/index drift first, because most reported
   `target_uid_unknown` UIDs still exist in current by-memory docs.
3. For exact-current target groups, prefer a validator-owned registration or
   revalidation-clear path after the UID appears in `[files]`.
4. For headerless multi-target reports, either:
   - de-execute and re-execute a corrected copy per target UID, or
   - choose the one canonical target UID only if the report truly covers one
     primary target and the rest are support docs.
5. For renamed/reranged target groups, use the current path/name/range as the
   source of truth before clearing revalidation.

## Headerless Or Multi-Target Reports

These reports contain useful source research, but they lack a single
`TARGET-REPORT-UID` header. The current docs they reference exist and are
registered. The issue is report lifecycle shape, not missing source evidence.

| Report | Current target docs found | Finding |
| --- | --- | --- |
| `executed-b-agent-research/B001/005971ad-threadman-watch-list-raw-cluster.md` | `0001K3`, `0001K4`, and `0001JX` Thread/ThreadMan docs | Broad ThreadMan watch-list cluster. Source information is useful, but it should not count as one target report without a target-specific execution. |
| `executed-b-agent-research/B001/B001-MEMTOOL-00506970-MapPaneInputPacketRenderCore.md` | `0001AT`, `0001AV`, `00037Q`, `00037Y` | Broad MapPane/Input/packet-render audit. Current docs are split more precisely than the report title; retarget only after choosing exact target scope. |
| `executed-b-agent-research/B002/00010C-00010G-clan-status-pane-ui-source-quality.md` | `00010C`, `00010G` | Report covers two ClanStatusPane targets and related support pages. Source route still looks correct; split or re-execute per target. |
| `executed-b-agent-research/B002/00012X-versatile-alert-pane-callbacks-source-quality.md` | `00012X`, `00012Y`, `000130`, `0002P1` | VersatileAlertPane callback/destructor/vtable family. Useful source-quality report, but too broad for one target header. |
| `executed-b-agent-research/B002/00020Z-000213-webboard-request-source-quality.md` | `00020Z`, `000213` | WebBoard request helper report spans two registered targets. Source context is current; needs target-specific lifecycle handling. |
| `executed-b-agent-research/B002/B002-MEMTOOL-004FE790-RawPasswordChangePacketWithAccount.md` | `0002QB` | Single current target is clear. Likely safe to retarget to `0002QB` after review. |
| `executed-b-agent-research/B002/B002-MEMTOOL-00514E60-SystemMessageMarkerScalarDeletingDestructor.md` | `0001B5` | Source/name changed materially: current target is `SharedLObjectScalarDeletingDestructor`, not `SystemMessageMarker...`. Treat as stale title/source-label drift; review before clearing. |
| `executed-b-agent-research/B002/B002-MEMTOOL-00553C10-ConnectionClosedReconnectDialogs.md` | `0001FT`, `0001FV` | Broad reconnect/copy-window dialog cluster. Useful, but multi-target. |
| `executed-b-agent-research/B002/B002-MEMTOOL-00559B90-ScreenDimmerAndFadeOut.md` | `0001GA` | Single current target is clear. Likely safe to retarget to `0001GA` after review. |
| `executed-b-agent-research/B002/B002-MEMTOOL-00573C38-SimpleListPaneDestructorThunks.md` | `0001HQ` | Single current target is clear, with support/ignored ranges nearby. Likely safe to retarget after review. |
| `executed-b-agent-research/B009/00020V-00020W-BrowserWindowWndProcClone-source-quality.md` | `00020V`, `00020W` | Intentional two-target Browser WndProc/raw-clone report. Source findings still look correct, but coverage needs target-specific execution. |
| `executed-b-agent-research/B010/0000Z6-BrowserControlPaneCore-source-quality.md` | `0000Z6` | Single current target is clear. Missing header appears to be the only lifecycle issue. |

## Renamed, Reranged, Or Source-Label Drift Cases

These should be reviewed before revalidation is cleared because the current
by-memory path/name/range differs from the report's older wording. In most of
these, the current docs already appear to incorporate the report's conclusion.

| UID | Current target | Finding |
| --- | --- | --- |
| `0003JP` | `by-memory/0x00630a14-0x00630a18.ChatInputPaneChevronPromptString.md` | Old report target was `SharedChevronPromptString`. Current doc says the B003 report was incorporated and the item was renamed/reowned to `ChatInputPane`. Source is likely correct now; old report path/name is stale. |
| `0003LZ` | `by-memory/0x004df500-0x004df668.ItemObjImageLibLoadItemInfoTable.md` | Old title/source label was `LightInfoTableLoader`. Current doc explicitly reclassifies it to `ItemObjImageLib` and rejects LightObj/LightInfo evidence. Treat the old report label as superseded. |
| `0003NC` | `by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md` | Report itself requested the endpoint correction from `...be2` to `...be3`; current doc has the corrected range and first-draft C++. Source appears current after rerange. |
| `0003O5` | `by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md` | Current target is split/renamed from the older broad `SelfSaveInputPane` span. Current source is constructor-specific and has C++. |
| `0003O7` | `by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md` | Current target is split/endpoint-corrected from older `...b0` wording. Current source is packet-helper-specific and has C++. |
| `0003UK` | `by-memory/0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md` | Current file title says `SetMovementBuffer`, but the formal C++ body is `CopyDeferredUserListPacket`. This is the strongest current-source inconsistency found in the quick pass; review before clearing. |
| `0003XE` | `by-memory/0x004bb260-0x004bb2d7.SurfaceTileBufferBlitRaw.md` | Older report text references `GrafPortSurfaceContextBlitRaw` and an older endpoint. Current target is `SurfaceTileBufferBlitRaw`, but summary/C++ are still blank. Needs manual source-route review before clearing. |
| `0003YQ` | `by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md` | Current doc corrects stale endpoint `...ea` to `...ec` and preserves no-live-route/no-C++ decision. Source appears current after rerange. |
| `000408` | `by-memory/0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructor.md` | Old report title said cleanup wrapper. Current doc resolves it as the ordinary BrowserPane non-deleting destructor with C++. Source appears current but title changed. |

Support-path drift was also observed in reports for `0003EB`, `0003GY`,
`0003IO`, `0003PN`, and `0003UT`, where some linked support pages were renamed,
split, or deleted. Their primary current target docs still exist; review support
references if those reports are re-executed.

## Exact Current Target Docs Missing From Validator Files Index

The following groups have report headers and current by-memory docs with the
same UID, but that UID is absent from `tools/validator.ini` `[files]`. This is
why the validator reports `target_uid_unknown`. Based on the sampled current
docs, these are mostly already-incorporated source-quality/no-owner/ownership
reports rather than invalid source reports.

Report counts are in parentheses.

```text
00037A(1), 00037C(1), 00037E(1), 00039J(1), 00039K(1), 00039R(2),
00039S(1), 00039T(1), 00039Y(1), 00039Z(1), 0003A2(1), 0003A3(1),
0003BM(1), 0003EB(1), 0003F4(6), 0003FH(1), 0003FY(11), 0003FZ(11),
0003G1(11), 0003G3(11), 0003G4(10), 0003G7(10), 0003GP(1),
0003GY(13), 0003H4(1), 0003IO(10), 0003JG(11), 0003JI(11),
0003JP(1), 0003LP(1), 0003LQ(4), 0003LZ(1), 0003M0(1), 0003M2(1),
0003M7(1), 0003M9(1), 0003MA(1), 0003N8(1), 0003N9(7), 0003NC(1),
0003O2(1), 0003O5(1), 0003O7(1), 0003P9(2), 0003PN(1), 0003U9(1),
0003UA(1), 0003UC(1), 0003UD(1), 0003UF(1), 0003UG(1), 0003UJ(1),
0003UK(1), 0003UR(1), 0003US(1), 0003UT(1), 0003UU(1), 0003V5(1),
0003VE(1), 0003VG(1), 0003VH(1), 0003VS(1), 0003VT(1), 0003VU(1),
0003VV(1), 0003VW(1), 0003VX(1), 0003W3(1), 0003W7(1), 0003W9(1),
0003WA(1), 0003WE(1), 0003WF(1), 0003XE(3), 0003YQ(1), 0003ZH(1),
0003ZJ(1), 0003ZL(1), 0003ZO(1), 000408(1)
```

## Representative Source Checks

- `0003ZH` current target is
  `by-memory/0x0057b350-0x0057b36a.SoundManagerStopRedbookAndCancelTrackTimerRaw.md`.
  The current doc includes the B015 recommendation, owner/emitter `0000DG`, and
  formal C++ for `SoundManager::StopRedbookAndCancelTrackTimer()`. Source looks
  correct; validator issue is indexing/registration.
- `0003FZ` current target is
  `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
  The current summary keeps `CANONICAL_OWNER:NONE` and emitters `0000JC,0000LE`
  with FileDownloader/MiniMap evidence. Source looks correct; the repeated
  reports are duplicate no-owner passes plus index drift.
- `0003G3`, `0003G4`, and `0003G7` current targets preserve shared
  ReconnectDialog/TerminalPane literal routing with no canonical owner. Source
  looks current; there are many duplicate passes.
- `0003H4` current target preserves LivingObjectPane ownership, no-live-route
  evidence, and blank C++. Source looks current; validator issue is index drift.
- `0003JP` source changed in the intended direction: old shared/parentless
  wording was superseded by current direct ChatInputPane ownership. Do not clear
  this as if the old path still exists; clear/retarget against the renamed file.
- `0003UK` needs a real review before clearing because the page title and C++
  function name disagree.
- `0003XE` needs a real review before clearing because current page metadata
  exists but the current summary/C++ remain blank and old report language refers
  to an older GrafPort/source-route framing.

## Conclusion

Most of the 209 reports are not bad source reports. The current docs usually
contain enough information to recover the intended source route, and sampled
docs show the report recommendations have often already been incorporated.

The safe next step is to repair the validator file-index drift, then handle the
12 headerless/multi-target reports and the small renamed/reranged group
explicitly. Only `0003UK`, `0003XE`, and the stale-title `0001B5` headerless
report look risky enough to require targeted source review before any
revalidation-clear action.
