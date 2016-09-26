/*ckwg +29
 * Copyright 2016 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief vital::detected_object_type C interface implementation
 */

#include "detected_object_type.h"

#include <vital/types/detected_object_type.h>

#include <vital/bindings/c/helpers/c_utils.h>
#include <vital/bindings/c/helpers/detected_object_type.h>

namespace kwiver {
namespace vital_c {

// Allocate our shared pointer cache object
SharedPointerCache< kwiver::vital::detected_object_type, vital_detected_object_type_t >
  DOT_SPTR_CACHE( "detected_object_type" );

} }


// ------------------------------------------------------------------
vital_detected_object_type_t* vital_detected_object_type_new()
{
  STANDARD_CATCH(
    "C::detected_object_type:new", 0,
    auto dot_sptr = std::make_shared< kwiver::vital::detected_object_type> ();

    kwiver::vital_c::DOT_SPTR_CACHE.store( dot_sptr );
    return reinterpret_cast<vital_detected_object_type_t*>( dot_sptr.get() );
  );
  return 0;
}


// ------------------------------------------------------------------
vital_detected_object_type_t* vital_detected_object_type_destroy(vital_detected_object_type_t* obj)
{
  STANDARD_CATCH(
    "C::detected_object_type::destroy", 0,
    kwiver::vital_c::DOT_SPTR_CACHE.erase( obj );
  );
}


// ------------------------------------------------------------------
vital_detected_object_type_t* vital_detected_object_type_new_from_list( vital_detected_object_type_t* obj,
                                                                        int count,
                                                                        char** class_names,
                                                                        double* scores)
{
  STANDARD_CATCH(
    "C::detected_object_type:new_from_list", 0,
    std::vector<std::string> names;
    std::vector< double > scores;
    for (int i = 0; i < count; ++i)
    {
      names.push_back(class_names[i]);
      scores.push_back(scores[i]);
    }
    auto dot_sptr = std::make_shared< kwiver::vital::detected_object_type> ( names, scores );
    kwiver::vital_c::DOT_SPTR_CACHE.store( dot_sptr );
    return reinterpret_cast<vital_detected_object_type_t*>( dot_sptr.get() );
  );
  return 0;
}


// ------------------------------------------------------------------
double vital_detected_object_type_score_from_class( vital_detected_object_type_t* obj, char* class_name )
{
  STANDARD_CATCH(
    "C::detected_object_type:score_from_class", 0,
    return kwiver::vital_c::DOT_SPTR_CACHE.get( obj )->score( std::string( class_name ));
    );
  return 0;
}


// ------------------------------------------------------------------
void vital_detected_object_type_get_most_likely( vital_detected_object_type_t* obj,
                                                 char* class_name, // out
                                                 double* score ) // out
{
  STANDARD_CATCH(
    "C::detected_object_type:score_from_class", 0,

    );
  //+ return through parameters - problem here
  //return kwiver::vital_c::DOT_SPTR_CACHE.get( obj )->score( std::string( class_name ));
}


// ------------------------------------------------------------------
void vital_detected_object_type_set_score( vital_detected_object_type_t* obj,
                                           char* class_name,
                                           double score)
{
  STANDARD_CATCH(
    "C::detected_object_type:score_from_class", 0,
    kwiver::vital_c::DOT_SPTR_CACHE.get( obj )->set_score( std::string( class_name ), score);
    );
}


// ------------------------------------------------------------------
void vital_detected_object_type_delete_score( vital_detected_object_type_t* obj,
                                              char* class_name)
{
  STANDARD_CATCH(
    "C::detected_object_type:score_from_class", 0,
    kwiver::vital_c::DOT_SPTR_CACHE.get( obj )->delete_score( std::string( class_name ) );
    );
}


// ------------------------------------------------------------------
char** vital_detected_object_type_class_names( vital_detected_object_type_t* obj,
                                               double thresh )
{
  STANDARD_CATCH(
    "C::detected_object_type:score_from_class", 0,
  auto name_vector = kwiver::vital_c::DOT_SPTR_CACHE.get( obj )->class_names();
  //+ create
    );
  return 0;
}


// ------------------------------------------------------------------
char** vital_detected_object_type_all_class_names(vital_detected_object_type_t* obj)
{
  STANDARD_CATCH(
    "C::detected_object_type:score_from_class", 0,


    );
  return 0;
}
