from __future__ import annotations

import contextlib
import io
import json
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace


TOOLS_DIR = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS_DIR))

import validator_background as validator


class ValidatorReconstructionHeaderTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temporary = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary.name) / "project-documentation"
        self.tools = self.root / "tools"
        self.tools.mkdir(parents=True)
        validator.DEFAULT_METADATA_CACHE = self.tools / "metadata-cache.json"
        validator._METADATA_CACHE = None
        validator._METADATA_CACHE_DIRTY = False
        validator._TEXT_CACHE.clear()
        validator._FILE_HASH_CACHE.clear()
        validator._RESOLVE_CACHE.clear()
        self.ini = self.tools / "validator.ini"
        self.config = validator.load_config(self.ini)

    def tearDown(self) -> None:
        self.temporary.cleanup()

    @staticmethod
    def managed_text(uid: str, cpp: str = "", header: str | None = None, newline: str = "\n") -> str:
        lines = [
            f"*** UID:{uid} | DO NOT MODIFY OR REMOVE!!! ***",
            "*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***",
            "*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***",
            "*** CANONICAL_OWNER:000002 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***",
            "*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***",
            "*** EMITTER_UIDS:000002 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***",
            "*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***",
            "*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***",
            validator.RECONSTRUCTION_CPP_BEGIN_LINE,
        ]
        if cpp:
            lines.extend(cpp.splitlines())
        lines.append(validator.RECONSTRUCTION_CPP_END_LINE)
        if header is not None:
            lines.append(validator.RECONSTRUCTION_H_BEGIN_LINE)
            if header:
                lines.extend(header.splitlines())
            lines.append(validator.RECONSTRUCTION_H_END_LINE)
        lines.extend(
            [
                "*** Item Summary: preserved summary | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***",
                "*** Nested:3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***",
                "",
                "# Body",
                "",
                "Body text.",
            ]
        )
        return newline.join(lines) + newline

    def add_doc(self, uid: str, folder: str, text: str) -> Path:
        path = self.root / folder / f"{uid}.md"
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text, encoding="utf-8", newline="")
        rel = path.relative_to(self.root).as_posix()
        self.config["files"][uid] = rel
        self.config["completion"][uid] = "90"
        self.config["confidence"][uid] = "90"
        return path

    def test_parser_supports_blank_nonblank_and_missing_blocks(self) -> None:
        missing = self.managed_text("000001", header=None).splitlines()
        self.assertEqual(("", "blank", []), validator.extract_reconstruction_header_code(missing))

        blank = self.managed_text("000001", header="   ").splitlines()
        self.assertEqual(("", "blank", []), validator.extract_reconstruction_header_code(blank))

        coded = self.managed_text("000001", header="struct Widget {};\n").splitlines()
        self.assertEqual(
            ("struct Widget {};", "block", []),
            validator.extract_reconstruction_header_code(coded),
        )

    def test_header_insertion_preserves_cpp_summary_nesting_and_body(self) -> None:
        path = self.add_doc("000001", "by-memory", self.managed_text("000001", cpp="int f() { return 1; }", header=None))
        original = path.read_text(encoding="utf-8")
        new_text, _, _, _, actions = validator.ensure_metadata_header(
            original,
            "000001",
            path,
            self.root,
            self.config,
            "ok",
        )
        self.assertEqual(1, sum(action.action == "reconstruction_h_insert" for action in actions))
        expected_without_h = new_text.replace(
            validator.RECONSTRUCTION_H_BEGIN_LINE + "\n" + validator.RECONSTRUCTION_H_END_LINE + "\n",
            "",
            1,
        )
        self.assertEqual(original, expected_without_h)
        self.assertIn("int f() { return 1; }", new_text)
        self.assertIn("Item Summary: preserved summary", new_text)
        self.assertIn("*** Nested:3 ", new_text)

        coverage_text, coverage_actions = validator.ensure_memory_coverage_metadata_lines(
            new_text,
            "000001",
            path,
            self.root,
        )
        self.assertEqual(new_text, coverage_text)
        self.assertEqual([], coverage_actions)

    def test_malformed_header_block_fails_closed(self) -> None:
        path = self.root / "by-memory" / "bad.md"
        path.parent.mkdir(parents=True)
        original = self.managed_text("000001", header=None).replace(
            validator.RECONSTRUCTION_CPP_END_LINE,
            validator.RECONSTRUCTION_CPP_END_LINE + "\n" + validator.RECONSTRUCTION_H_BEGIN_LINE,
            1,
        )
        path.write_text(original, encoding="utf-8")
        new_text, _, _, _, actions = validator.ensure_metadata_header(
            original,
            "000001",
            path,
            self.root,
            self.config,
            "ok",
        )
        self.assertEqual(original, new_text)
        self.assertTrue(any(action.action == "reconstruction_h_invalid" for action in actions))

    def test_dual_channel_assembly_keeps_cpp_and_header_independent(self) -> None:
        root_uid = "000002"
        child_uid = "000001"
        metadata = validator.AutogenMetadata(
            uid=child_uid,
            path="by-memory/000001.md",
            folder="by-memory",
            eligible=True,
            reconstructable="true",
            emitter_uids=[root_uid],
            code="int Widget::Value() { return 1; }",
            code_mode="block",
            header_code="struct Widget { int Value(); };",
            header_code_mode="block",
        )
        self.config["files"][root_uid] = "by-file/Widget.md"
        self.config["files"][child_uid] = metadata.path
        cpp, header, coded, header_coded = validator.assemble_autogen_root(
            root_uid,
            {child_uid: metadata},
            {root_uid: [child_uid]},
            {child_uid: "emits"},
            self.root,
            self.config,
            [],
        )
        self.assertIn("Widget::Value", cpp)
        self.assertNotIn("struct Widget", cpp)
        self.assertIn("struct Widget", header)
        self.assertNotIn("Widget::Value() {", header)
        self.assertEqual({child_uid}, coded)
        self.assertEqual({child_uid}, header_coded)

    def test_header_children_marker_uses_only_header_children(self) -> None:
        root_uid = "000003"
        parent_uid = "000002"
        child_uid = "000001"
        parent = validator.AutogenMetadata(
            uid=parent_uid,
            path="by-class/Widget.md",
            folder="by-class",
            eligible=True,
            reconstructable="true",
            emitter_uids=[root_uid],
            code="// cpp parent\n[[CHILDREN]]\n// cpp end",
            code_mode="block",
            header_code="struct Widget {\n[[CHILDREN]]\n};",
            header_code_mode="block",
        )
        child = validator.AutogenMetadata(
            uid=child_uid,
            path="by-memory/WidgetValue.md",
            folder="by-memory",
            eligible=True,
            reconstructable="true",
            emitter_uids=[parent_uid],
            code="int Widget::Value() { return 1; }",
            code_mode="block",
            header_code="int Value();",
            header_code_mode="block",
        )
        self.config["files"][root_uid] = "by-file/Widget.md"
        self.config["files"][parent_uid] = parent.path
        self.config["files"][child_uid] = child.path
        cpp, header, _, _ = validator.assemble_autogen_root(
            root_uid,
            {parent_uid: parent, child_uid: child},
            {root_uid: [parent_uid], parent_uid: [child_uid]},
            {parent_uid: "emits", child_uid: "emits"},
            self.root,
            self.config,
            [],
        )
        self.assertIn("Widget::Value", cpp)
        self.assertNotIn("int Value();", cpp)
        self.assertIn("int Value();", header)
        self.assertNotIn("Widget::Value() {", header)
        self.assertLess(header.index("int Value();"), header.index("};"))

    def test_nonblank_header_without_emitter_route_is_an_error(self) -> None:
        path = self.root / "by-memory" / "000001.md"
        path.parent.mkdir(parents=True)
        metadata = validator.AutogenMetadata(
            uid="000001",
            path="by-memory/000001.md",
            folder="by-memory",
            eligible=True,
            reconstructable="true",
            header_code="struct Unrouted;",
            header_code_mode="block",
            header_code_hash=validator.code_hash("struct Unrouted;"),
            errors=[],
        )
        actions = validator.update_autogen_registry_for_metadata(
            self.root,
            self.config,
            metadata,
            path,
            True,
        )
        error = self.config[validator.AUTOGEN_ERROR_SECTION][validator.autogen_error_key("000001")]
        self.assertIn("emitter_header_without_route", error)
        self.assertTrue(any(action.action == "autogen_value_invalid" for action in actions))

    def test_autogen_creates_and_then_removes_header_without_empty_placeholder(self) -> None:
        root_uid = "000002"
        child_uid = "000001"
        root_doc = self.root / "by-file" / "Widget.md"
        root_doc.parent.mkdir(parents=True)
        root_doc.write_text(f"*** UID:{root_uid} | DO NOT MODIFY OR REMOVE!!! ***\n", encoding="utf-8")
        child = self.add_doc(child_uid, "by-memory", self.managed_text(child_uid, header="struct Widget {};"))
        self.config["files"][root_uid] = "by-file/Widget.md"
        self.config[validator.PROJECTED_PATH_SECTION][root_uid] = "NexusTK/app/"
        self.config[validator.PROJECTED_PATH_STATUS_SECTION][root_uid] = "valid"
        self.config[validator.CANONICAL_OWNER_SECTION][root_uid] = "FILE"
        self.config[validator.RECONSTRUCTABLE_SECTION][child_uid] = "true"
        cpp_path = self.root / "auto-generated" / "NexusTK" / "app" / "Widget.cpp"
        cpp_path.parent.mkdir(parents=True)
        cpp_path.write_text("", encoding="utf-8")

        actions = validator.run_autogen_generation(
            self.root,
            self.config,
            True,
            command_context=validator.CommandContext(1, "000000000001", "2026-07-24T12:00:00-04:00"),
        )
        header_path = cpp_path.with_suffix(".h")
        self.assertTrue(header_path.exists())
        generated = header_path.read_text(encoding="utf-8")
        self.assertIn("// validator-command-id: 000000000001", generated)
        self.assertIn("struct Widget {};", generated)
        self.assertTrue(any(action.action == "autogen_header_create" for action in actions))
        self.assertEqual("block", self.config[validator.RECONSTRUCTION_H_CODE_MODE_SECTION][child_uid])
        self.assertEqual(
            validator.code_hash("struct Widget {};"),
            self.config[validator.RECONSTRUCTION_H_CODE_HASH_SECTION][child_uid],
        )

        child.write_text(self.managed_text(child_uid, header=""), encoding="utf-8")
        validator._METADATA_CACHE = None
        validator._TEXT_CACHE.clear()
        actions = validator.run_autogen_generation(
            self.root,
            self.config,
            True,
            affected_uids={child_uid},
            affected_paths={"by-memory/000001.md"},
            command_context=validator.CommandContext(2, "000000000002", "2026-07-24T12:01:00-04:00"),
        )
        self.assertFalse(header_path.exists())
        self.assertTrue(any(action.action == "autogen_header_stale_delete" for action in actions))
        self.assertTrue(cpp_path.exists())
        self.assertEqual("blank", self.config[validator.RECONSTRUCTION_H_CODE_MODE_SECTION][child_uid])
        self.assertEqual("", self.config[validator.RECONSTRUCTION_H_CODE_HASH_SECTION][child_uid])

    def test_projected_path_move_keeps_cpp_and_header_together(self) -> None:
        uid = "000002"
        old_doc_rel = "by-file/Widget.md"
        old_projected = "NexusTK/old/"
        new_projected = "NexusTK/new/"
        doc_path = self.root / old_doc_rel
        doc_path.parent.mkdir(parents=True)
        doc_path.write_text(f"*** UID:{uid} | DO NOT MODIFY OR REMOVE!!! ***\n", encoding="utf-8")
        old_cpp = validator.generated_cpp_path(self.root, old_projected, doc_path.stem)
        old_header = validator.generated_header_path(self.root, old_projected, doc_path.stem)
        old_cpp.parent.mkdir(parents=True)
        context = validator.CommandContext(1, "000000000001", "2026-07-24T12:00:00-04:00")
        old_cpp.write_text(
            validator.generated_cpp_content(uid, old_doc_rel, "int value;", context, "test"),
            encoding="utf-8",
        )
        old_header.write_text(
            validator.generated_header_content(uid, old_doc_rel, "extern int value;", context, "test"),
            encoding="utf-8",
        )

        actions = validator.sync_generated_cpp(
            self.root,
            uid,
            doc_path,
            old_doc_rel,
            old_projected,
            new_projected,
            True,
        )
        new_cpp = validator.generated_cpp_path(self.root, new_projected, doc_path.stem)
        new_header = validator.generated_header_path(self.root, new_projected, doc_path.stem)
        self.assertFalse(old_cpp.exists())
        self.assertFalse(old_header.exists())
        self.assertTrue(new_cpp.exists())
        self.assertTrue(new_header.exists())
        self.assertEqual(uid, validator.generated_source_uid(new_cpp))
        self.assertEqual(uid, validator.generated_source_uid(new_header))
        self.assertTrue(any(action.action == "projected_cpp_move" for action in actions))
        self.assertTrue(any(action.action == "projected_header_move" for action in actions))

    def test_header_destination_collision_aborts_the_whole_pair_move(self) -> None:
        uid = "000002"
        other_uid = "000003"
        old_doc_rel = "by-file/Widget.md"
        old_projected = "NexusTK/old/"
        new_projected = "NexusTK/new/"
        doc_path = self.root / old_doc_rel
        doc_path.parent.mkdir(parents=True)
        doc_path.write_text(f"*** UID:{uid} | DO NOT MODIFY OR REMOVE!!! ***\n", encoding="utf-8")
        old_cpp = validator.generated_cpp_path(self.root, old_projected, doc_path.stem)
        old_header = validator.generated_header_path(self.root, old_projected, doc_path.stem)
        new_header = validator.generated_header_path(self.root, new_projected, doc_path.stem)
        old_cpp.parent.mkdir(parents=True)
        new_header.parent.mkdir(parents=True)
        context = validator.CommandContext(1, "000000000001", "2026-07-24T12:00:00-04:00")
        old_cpp.write_text(validator.generated_cpp_content(uid, old_doc_rel, "int value;", context, "test"), encoding="utf-8")
        old_header.write_text(validator.generated_header_content(uid, old_doc_rel, "extern int value;", context, "test"), encoding="utf-8")
        new_header.write_text(validator.generated_header_content(other_uid, "by-file/Other.md", "int other;", context, "test"), encoding="utf-8")

        actions = validator.sync_generated_cpp(
            self.root,
            uid,
            doc_path,
            old_doc_rel,
            old_projected,
            new_projected,
            True,
        )
        self.assertTrue(old_cpp.exists())
        self.assertTrue(old_header.exists())
        self.assertEqual(other_uid, validator.generated_source_uid(new_header))
        self.assertTrue(any(action.action == "projected_header_conflict" for action in actions))
        self.assertFalse(any(action.action.endswith("_move") for action in actions))

    def test_autogen_report_exposes_header_code_and_destination(self) -> None:
        entry = validator.AutogenReportEntry(
            uid="000001",
            path="by-memory/000001.md",
            folder="by-memory",
            status="coded",
            has_code=True,
            has_header_code=True,
            destination="auto-generated/NexusTK/app/Widget.cpp",
            header_destination="auto-generated/NexusTK/app/Widget.h",
        )
        rendered = validator.render_autogen_report(
            "Fixture",
            [entry],
            validator.CommandContext(1, "000000000001", "2026-07-24T12:00:00-04:00"),
            "test",
        )
        self.assertIn("| Header Code |", rendered)
        self.assertIn("| Header Destination |", rendered)
        self.assertIn("`auto-generated/NexusTK/app/Widget.h`", rendered)

    def test_staging_preserves_crlf_and_no_final_newline(self) -> None:
        original = (
            b"*** UID:000001 | DO NOT MODIFY OR REMOVE!!! ***\r\n"
            + validator.RECONSTRUCTION_CPP_BEGIN_LINE.encode("ascii")
            + b"\r\nint x;\r\n"
            + validator.RECONSTRUCTION_CPP_END_LINE.encode("ascii")
        )
        staged, inserted, offset, classification, error = validator.stage_reconstruction_h_bytes(original)
        self.assertEqual("changed", classification)
        self.assertIsNone(error)
        self.assertFalse(staged.endswith(b"\r\n"))
        self.assertIn(validator.RECONSTRUCTION_H_BEGIN_LINE.encode("ascii"), staged)
        self.assertEqual(original, staged[:offset] + staged[offset + len(inserted):])

    def test_dedicated_migration_requires_reviewed_hashes(self) -> None:
        path = self.root / "by-memory" / "000001.md"
        path.parent.mkdir(parents=True)
        path.write_text(self.managed_text("000001", header=None), encoding="utf-8")
        args = SimpleNamespace(
            migration_id="fixture-migration",
            apply=False,
            dry_run=False,
            use_existing_dryrun=False,
            verbose=False,
            command_id=1,
            command_id_display="000000000001",
            command_timestamp="2026-07-24T12:00:00-04:00",
        )
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(0, validator.run_migrate_reconstruction_h(args, self.root, self.ini, self.tools / "lock"))
        manifest_path = validator.reconstruction_h_manifest_path(self.ini, "fixture-migration")
        manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
        self.assertEqual("staged", manifest["status"])
        self.assertEqual(1, manifest["changed_count"])
        self.assertNotIn(validator.RECONSTRUCTION_H_BEGIN_LINE, path.read_text(encoding="utf-8"))

        args.apply = True
        with contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(0, validator.run_migrate_reconstruction_h(args, self.root, self.ini, self.tools / "lock"))
        self.assertIn(validator.RECONSTRUCTION_H_BEGIN_LINE, path.read_text(encoding="utf-8"))
        manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
        self.assertEqual("applied", manifest["status"])
        journal = manifest_path.parent / manifest["progress_journal"]
        journal_rows = [json.loads(line) for line in journal.read_text(encoding="utf-8").splitlines()]
        self.assertEqual(["by-memory/000001.md"], [row["path"] for row in journal_rows])
        backup = manifest_path.parent / "backup" / "by-memory" / "000001.md"
        self.assertTrue(backup.exists())
        self.assertNotIn(validator.RECONSTRUCTION_H_BEGIN_LINE, backup.read_text(encoding="utf-8"))

    def test_migration_hash_drift_aborts_before_write(self) -> None:
        path = self.root / "by-memory" / "000001.md"
        path.parent.mkdir(parents=True)
        path.write_text(self.managed_text("000001", header=None), encoding="utf-8")
        args = SimpleNamespace(
            migration_id="drift",
            apply=False,
            dry_run=False,
            use_existing_dryrun=False,
            verbose=False,
            command_id=2,
            command_id_display="000000000002",
            command_timestamp="2026-07-24T12:00:00-04:00",
        )
        with contextlib.redirect_stdout(io.StringIO()):
            validator.run_migrate_reconstruction_h(args, self.root, self.ini, self.tools / "lock")
        path.write_text(path.read_text(encoding="utf-8") + "changed after staging\n", encoding="utf-8")
        args.apply = True
        with self.assertRaisesRegex(SystemExit, "live source hash drift"):
            validator.run_migrate_reconstruction_h(args, self.root, self.ini, self.tools / "lock")
        self.assertNotIn(validator.RECONSTRUCTION_H_BEGIN_LINE, path.read_text(encoding="utf-8"))


if __name__ == "__main__":
    unittest.main()
