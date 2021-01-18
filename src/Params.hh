/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR                                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED 'AS IS' AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
////////////////////////////////////////////
// Params.hh
//
// TDRP header file for 'Params' class.
//
// Code for program samurai
//
// This header file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.hh
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @class Params
 *
 * @author automatically generated
 *
 */

#ifndef Params_hh
#define Params_hh

#include <tdrp/tdrp.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>

using namespace std;

// Class definition

class Params {

public:

  // enum typedefs

  typedef enum {
    INTERP_NONE = 0,
    INTERP_SPLINE = 1,
    INTERP_KD_TREE = 2,
    INTERP_FRACTL = 3
  } bkgd_interp_method_t;

  typedef enum {
    MODE_XYZ = 0,
    MODE_RTZ = 1
  } mode_t;

  typedef enum {
    PROJ_LAMBERT_CONFORMAL_CONIC = 0,
    PROJ_TRANSVERSE_MERCATOR_EXACT = 1
  } projection_t;

  ///////////////////////////
  // Member functions
  //

  ////////////////////////////////////////////
  // Default constructor
  //

  Params ();

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params (const Params&);

  ////////////////////////////////////////////
  // Destructor
  //

  virtual ~Params ();

  ////////////////////////////////////////////
  // Assignment
  //

  void operator=(const Params&);

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadFromArgs(int argc, char **argv,
                   char **override_list,
                   char **params_path_p,
                   bool defer_exit = false);

  bool exitDeferred() { return (_exitDeferred); }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadApplyArgs(const char *params_path,
                    int argc, char **argv,
                    char **override_list,
                    bool defer_exit = false);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  static bool isArgValid(const char *arg);

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  // return number of args consumed.
  //

  static int isArgValidN(const char *arg);

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int load(const char *param_file_path,
           char **override_list,
           int expand_env, int debug);

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadFromBuf(const char *param_source_str,
                  char **override_list,
                  const char *inbuf, int inlen,
                  int start_line_num,
                  int expand_env, int debug);

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int loadDefaults(int expand_env);

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void sync() const;

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void print(FILE *out, tdrp_print_mode_t mode = PRINT_NORM);

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int checkAllSet(FILE *out);

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int checkIsSet(const char *param_name);

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int arrayRealloc(const char *param_name,
                   int new_array_n);

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int array2DRealloc(const char *param_name,
                     int new_array_n1,
                     int new_array_n2);

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void freeAll(void);

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  static void usage(ostream &out);

  ///////////////////////////
  // Data Members
  //

  char _start_; // start of data region
                // needed for zeroing out data
                // and computing offsets

  tdrp_bool_t debug_bgu;

  char* debug_bgu_nc;

  tdrp_bool_t debug_bgin;

  char* debug_bgu_overwrite;

  int debug_kd;

  int debug_kd_step;

  tdrp_bool_t load_background;

  tdrp_bool_t load_bg_coefficients;

  tdrp_bool_t adjust_background;

  bkgd_interp_method_t bkgd_obs_interpolation;

  mode_t mode;

  projection_t projection;

  char* data_directory;

  char* output_directory;

  tdrp_bool_t preprocess_obs;

  int num_iterations;

  tdrp_bool_t output_mish;

  tdrp_bool_t output_txt;

  tdrp_bool_t output_qc;

  tdrp_bool_t output_netcdf;

  tdrp_bool_t output_asi;

  tdrp_bool_t output_COAMPS;

  tdrp_bool_t save_mish;

  float i_min;

  float i_max;

  float i_incr;

  float j_min;

  float j_max;

  float j_incr;

  float k_min;

  float k_max;

  float k_incr;

  char* ref_state;

  char* ref_time;

  float i_background_roi;

  float j_background_roi;

  int radar_skip;

  int radar_stride;

  int dynamic_stride;

  char* qr_variable;

  char* radar_dbz;

  char* radar_vel;

  char* radar_sw;

  float i_reflectivity_roi;

  float j_reflectivity_roi;

  float k_reflectivity_roi;

  float dbz_pseudow_weight;

  float mask_reflectivity;

  float melting_zone_width;

  float mixed_phase_dbz;

  float rain_dbz;

  char* i_rhou_bcL;

  char* i_rhou_bcR;

  char* i_rhov_bcL;

  char* i_rhov_bcR;

  char* i_rhow_bcL;

  char* i_rhow_bcR;

  char* i_tempk_bcL;

  char* i_tempk_bcR;

  char* i_qv_bcL;

  char* i_qv_bcR;

  char* i_rhoa_bcL;

  char* i_rhoa_bcR;

  char* i_qr_bcL;

  char* i_qr_bcR;

  char* j_rhou_bcL;

  char* j_rhou_bcR;

  char* j_rhov_bcL;

  char* j_rhov_bcR;

  char* j_rhow_bcL;

  char* j_rhow_bcR;

  char* j_tempk_bcL;

  char* j_tempk_bcR;

  char* j_qv_bcL;

  char* j_qv_bcR;

  char* j_rhoa_bcL;

  char* j_rhoa_bcR;

  char* j_qr_bcL;

  char* j_qr_bcR;

  char* k_rhou_bcL;

  char* k_rhou_bcR;

  char* k_rhov_bcL;

  char* k_rhov_bcR;

  char* k_rhow_bcL;

  char* k_rhow_bcR;

  char* k_tempk_bcL;

  char* k_tempk_bcR;

  char* k_qv_bcL;

  char* k_qv_bcR;

  char* k_rhoa_bcL;

  char* k_rhoa_bcR;

  char* k_qr_bcL;

  char* k_qr_bcR;

  float dropsonde_rhoa_error;

  float dropsonde_rhou_error;

  float dropsonde_rhov_error;

  float dropsonde_rhow_error;

  float dropsonde_tempk_error;

  float dropsonde_qv_error;

  float dropsonde_rhoua_error;

  float flightlevel_rhoa_error;

  float flightlevel_rhou_error;

  float flightlevel_rhov_error;

  float flightlevel_rhow_error;

  float flightlevel_tempk_error;

  float flightlevel_qv_error;

  float flightlevel_rhoua_error;

  float mtp_rhoa_error;

  float mtp_tempk_error;

  float insitu_rhoa_error;

  float insitu_rhou_error;

  float insitu_rhov_error;

  float insitu_rhow_error;

  float insitu_tempk_error;

  float insitu_qv_error;

  float insitu_rhoua_error;

  float sfmr_windspeed_error;

  float qscat_rhou_error;

  float qscat_rhov_error;

  float ascat_rhou_error;

  float ascat_rhov_error;

  float amv_rhou_error;

  float amv_rhov_error;

  float lidar_sw_error;

  float lidar_power_error;

  float lidar_min_error;

  float radar_sw_error;

  float radar_fallspeed_error;

  float radar_min_error;

  float aeri_qv_error;

  float aeri_rhoa_error;

  float aeri_rhou_error;

  float aeri_rhov_error;

  float aeri_rhow_error;

  float aeri_tempk_error;

  float bg_obs_error;

  float bg_interpolation_error;

  float mesonet_qv_error;

  float mesonet_rhoa_error;

  float mesonet_rhou_error;

  float mesonet_rhov_error;

  float mesonet_rhow_error;

  float mesonet_tempk_error;

  float output_latlon_increment;

  float output_pressure_increment;

  float max_radar_elevation;

  tdrp_bool_t horizontal_radar_appx;

  tdrp_bool_t allow_background_missing_values;

  tdrp_bool_t allow_negative_angles;

  char* array_order;

  char* bg_interpolation;

  float bkgd_kd_max_distance;

  int bkgd_kd_num_neighbors;

  char* fractl_nc_file;

  tdrp_bool_t use_fractl_errors;

  float *_mc_weight;
  int mc_weight_n;

  float *_bg_qr_error;
  int bg_qr_error_n;

  float *_bg_qv_error;
  int bg_qv_error_n;

  float *_bg_rhoa_error;
  int bg_rhoa_error_n;

  float *_bg_rhou_error;
  int bg_rhou_error_n;

  float *_bg_rhov_error;
  int bg_rhov_error_n;

  float *_bg_rhow_error;
  int bg_rhow_error_n;

  float *_bg_tempk_error;
  int bg_tempk_error_n;

  float *_i_filter_length;
  int i_filter_length_n;

  float *_j_filter_length;
  int j_filter_length_n;

  float *_k_filter_length;
  int k_filter_length_n;

  float *_i_spline_cutoff;
  int i_spline_cutoff_n;

  float *_j_spline_cutoff;
  int j_spline_cutoff_n;

  float *_k_spline_cutoff;
  int k_spline_cutoff_n;

  float *_i_max_wavenumber;
  int i_max_wavenumber_n;

  float *_j_max_wavenumber;
  int j_max_wavenumber_n;

  float *_k_max_wavenumber;
  int k_max_wavenumber_n;

  char _end_; // end of data region
              // needed for zeroing out data

private:

  void _init();

  mutable TDRPtable _table[188];

  const char *_className;

  bool _exitDeferred;

};

#endif

